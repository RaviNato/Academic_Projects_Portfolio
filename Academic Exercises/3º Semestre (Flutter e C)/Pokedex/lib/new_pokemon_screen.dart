import 'package:flutter/material.dart';
import 'pokemon_service.dart';
import 'home_screen.dart';

class NewPokemonScreen extends StatefulWidget {
  const NewPokemonScreen({super.key});

  @override
  State<NewPokemonScreen> createState() => _NewPokemonScreenState();
}

class _NewPokemonScreenState extends State<NewPokemonScreen> {
  final _service = PokemonService();
  late Future<List<Map<String, dynamic>>> _searchFuture;
  final _queryController = TextEditingController();
  bool _isSaving = false;


  @override
  void initState() {
    super.initState();
    _searchFuture = _loadPokemonList();
  }

  // Função auxiliar para carregar a lista com detalhes (imagem/tipos)
  Future<List<Map<String, dynamic>>> _loadPokemonList({String? query}) async {
    List<String> names;
    if (query == null || query.isEmpty) {
      names = await _service.fetchPokemonNames();
    } else {
      names = await _service.fetchPokemonByName(query.toLowerCase());
    }

    // Busca os detalhes de cada pokemon da lista em paralelo
    return Future.wait(names.map((name) => _service.fetchPokemonDetails(name)));
  }

  void _buscar() {
    setState(() {
      _searchFuture = _loadPokemonList(query: _queryController.text.trim());
    });
  }

  Future<void> _selectAndSave(Map<String, dynamic> pokemon) async {
    setState(() => _isSaving = true);
    try {
      await collection.add({
        'name': pokemon['name'],
        'spriteId': pokemon['spriteId'],
        'spriteUrl': pokemon['spriteUrl'],
        'moves': pokemon['moves'],
        'types': pokemon['types'],
        'level': 10,
      });

      if (mounted) Navigator.pop(context);
    } catch (e) {
      setState(() => _isSaving = false);
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(content: Text('Erro ao salvar Pokémon')),
      );
    }
  }

  String _capitalize(String text) {
    if (text.isEmpty) return text;
    return text[0].toUpperCase() + text.substring(1);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: const Color(0xFF171719),
      appBar: AppBar(
        title: const Text('Selecionar Pokémon'),
        backgroundColor: const Color.fromARGB(255, 212, 12, 55),
        foregroundColor: Colors.white,
      ),
      body: _isSaving
          ? const Center(child: CircularProgressIndicator())
          : Padding(
              padding: const EdgeInsets.all(16.0),
              child: Column(
                children: [
                  Row(
                    children: [
                      Expanded(
                        child: TextField(
                          controller: _queryController,
                          style: const TextStyle(color: Colors.white),
                          decoration: const InputDecoration(
                            border: OutlineInputBorder(),
                            labelText: 'Buscar Pokémon',
                            labelStyle: TextStyle(color: Colors.white70),
                          ),
                          onSubmitted: (_) => _buscar(),
                        ),
                      ),
                      IconButton(
                        icon: const Icon(Icons.search, color: Colors.white),
                        onPressed: _buscar,
                      ),
                    ],
                  ),
                  const SizedBox(height: 20),
                  Expanded(
                    child: FutureBuilder<List<Map<String, dynamic>>>(
                      future: _searchFuture,
                      builder: (context, snapshot) {
                        if (snapshot.connectionState == ConnectionState.waiting) {
                          return const Center(child: CircularProgressIndicator());
                        }
                        if (snapshot.hasError) {
                          return const Center(
                            child: Text('Pokémon não encontrado',
                                style: TextStyle(color: Colors.white)),
                          );
                        }

                        final list = snapshot.data ?? [];
                        return ListView.builder(
                          itemCount: list.length,
                          itemBuilder: (context, index) {
                            final pokemon = list[index];
                            final List<String> types = List<String>.from(pokemon['types']);

                            return Card(
                              color: const Color(0xFF38353D),
                              margin: const EdgeInsets.symmetric(vertical: 8),
                              child: ListTile(
                                contentPadding: const EdgeInsets.all(12),
                                leading: CircleAvatar(
                                  radius: 25,
                                  backgroundColor: Colors.indigo.shade100,
                                  backgroundImage: NetworkImage(pokemon['spriteUrl']),
                                ),
                                title: Column(
                                  crossAxisAlignment: CrossAxisAlignment.start,
                                  children: [
                                    Text(
                                      _capitalize(pokemon['name']),
                                      style: const TextStyle(
                                          color: Colors.white,
                                          fontWeight: FontWeight.bold,
                                          fontSize: 18),
                                    ),
                                    const SizedBox(height: 4),
                                    Row(
                                      children: types.map((typeId) {
                                        return Padding(
                                          padding: const EdgeInsets.only(right: 4),
                                          child: Image.network(
                                            'https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/types/generation-iii/firered-leafgreen/$typeId.png',
                                            height: 16,
                                          ),
                                        );
                                      }).toList(),
                                    ),
                                  ],
                                ),
                                trailing: const Icon(Icons.add_circle_outline, color: Colors.white54),
                                onTap: () => _selectAndSave(pokemon),
                              ),
                            );
                          },
                        );
                      },
                    ),
                  ),
                ],
              ),
            ),
    );
  }

  @override
  void dispose() {
    _queryController.dispose();
    super.dispose();
  }
}