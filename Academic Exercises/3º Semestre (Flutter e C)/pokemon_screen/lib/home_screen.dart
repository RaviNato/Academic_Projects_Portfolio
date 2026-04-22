import 'package:flutter/material.dart';
import 'package:pokemon_screen/pokemon_screen.dart';
import 'package:pokemon_screen/pokemon.dart';

class HomeScreen extends StatefulWidget {
  const HomeScreen({super.key});

  @override
  State<HomeScreen> createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  final List<Pokemon> pokemons = [
    Pokemon(name: 'Mew', spriteId: 151, typeIds: [14], level: 50, 
    moves: ['Recover', 'Psyshock', 'Psystrike', 'Transform']),
    Pokemon(name: 'Gengar', spriteId: 94, typeIds: [8, 4], level: 42,
    moves: ['Hypnosis', 'Dream Eater', 'Shadow Ball', 'Lick']),
    Pokemon(name: 'Charizard', spriteId: 6, typeIds: [10, 3], level: 38,
    moves: ['Flamethrower', 'Fly', 'Slash', 'Dragon Rage']),
    Pokemon(name: 'Pikachu', spriteId: 25, typeIds: [13], level: 25,
    moves: ['Thunderbolt', 'Quick Attack', 'Iron Tail', 'Volt Tackle']),
  ];


  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Color(0xFF171719),
      appBar: AppBar(
        title: const Text('Pokédex'),
        backgroundColor: const Color.fromARGB(255, 212, 12, 55),
        foregroundColor: Colors.white,
        centerTitle: true,
      ),
      
      body: ListView.builder(
        itemCount: pokemons.length,
        itemBuilder: (context, index) {
          final pokemon = pokemons[index];
          
          return Card(
            color: Color(0xFF38353D),
            margin: const EdgeInsets.symmetric(horizontal: 10, vertical: 10),
            child: ListTile(
              leading: CircleAvatar(
                backgroundColor: Colors.indigo.shade100,
                backgroundImage: NetworkImage(pokemon.spriteUrl), 
              ),

              title: Text(
                pokemon.name,
                style: const TextStyle(color: Colors.white, fontWeight: FontWeight.bold),
              ),

              subtitle: Text('Nível ${pokemon.level}', style: TextStyle(color: Colors.white)),

              trailing: const Icon(Icons.chevron_right),

              onTap:() async {
                final int? novoNivel = await Navigator.push<int>(
                  context,
                  MaterialPageRoute(builder: (context) => PokemonScreen(pokemon: pokemon)),
                );

                if (novoNivel != null) {
                  setState(() {
                    pokemon.level = novoNivel;
                  });
                }
              },
            ),
          );
        },
      ),
    );
  }
}