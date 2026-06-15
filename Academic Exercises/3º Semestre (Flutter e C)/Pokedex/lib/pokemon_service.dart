import 'dart:convert';
import 'package:http/http.dart' as http;

class PokemonService {
  final String baseUrl = 'https://pokeapi.co/api/v2/pokemon';

  Future<List<String>> fetchPokemonNames() async {
    final response = await http.get(Uri.parse('$baseUrl?limit=20'));
    if (response.statusCode == 404) throw Exception('Erro ${response.statusCode}');

    final data = jsonDecode(response.body) as Map<String, dynamic>;
    
    List<String> names = (data['results'] as List)
        .map((pokemon) => pokemon['name'] as String)
        .toList();
    
    return names;
  }

  Future<List<String>> fetchPokemonByName(String name) async {
    final response = await http.get(Uri.parse('$baseUrl/$name'));
    
    if (response.statusCode == 404) throw Exception('Pokémon não encontrado');
    
    
    final data = jsonDecode(response.body);
    return [data['name']as String];
  }

  Future<Map<String, dynamic>> fetchPokemonDetails(String name) async {
    final response = await http.get(Uri.parse('$baseUrl/$name'));

    if (response.statusCode == 404) throw Exception('Pokémon não encontrado');

    final data = jsonDecode(response.body);
    
    int id = data['id'];
    String? spriteUrl = data['sprites']['front_default'];
    // Fallback para CDN caso front_default seja null
    spriteUrl ??= 'https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/$id.png';

    // Mapa para converter o nome do tipo no ID da imagem da PokeAPI
    final Map<String, String> _typeIds = {
      'normal': "1", 'fighting': "2", 'flying': "3", 'poison': "4", 'ground': "5",
      'rock': "6", 'bug': "7", 'ghost': "8", 'steel': "9", 'fire': "10",
      'water': "11", 'grass': "12", 'electric': "13", 'psychic': "14", 'ice': "15",
      'dragon': "16", 'dark': "17", 'fairy': "18"
    };
    List<String> types = (data['types'] as List)
      .map((t) => _typeIds[t['type']['name'] as String] ?? "1")
      .toList();

    List<String> moves = (data['moves'] as List)
      .take(4)
      .map((m) {
        String moveName = m['move']['name'] as String;
        moveName = moveName.replaceAll('-', ' ');
        return moveName[0].toUpperCase() + moveName.substring(1);
      })
      .toList();

    return {
      'name': data['name'][0].toUpperCase() + data['name'].substring(1),
      'spriteId': id,
      'spriteUrl': spriteUrl,
      'types': types,
      'moves': moves,
    };
  }
}