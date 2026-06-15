import 'package:flutter/material.dart';
import 'package:pokemon_screen/pokemon_screen/battle_panel.dart';
import 'package:pokemon_screen/pokemon_screen/pokemon_card.dart';
import 'package:pokemon_screen/pokemon_screen/move_list.dart';

class PokemonScreen extends StatelessWidget {
  final Map<String, dynamic> pokemon;
  final String docId;

  const PokemonScreen({
    super.key, 
    required this.pokemon,
    required this.docId,
  });


  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Color(0xFF171719),
      appBar: AppBar(
        title: Text(pokemon['name']),
        backgroundColor: const Color.fromARGB(255, 212, 12, 55),
        foregroundColor: Colors.white,
        centerTitle: true,
      ),

      body: Padding(
        padding: const EdgeInsets.all(16),
        child: Column(
          children: [
            PokemonCard(
              name: pokemon['name'],
              spriteUrl: pokemon['spriteUrl'],
              types: pokemon['types'].cast<String>(),
            ),
            SizedBox(height: 16),
              BattlePanel(
                level: pokemon['level'],
                name: pokemon['name'],
                docId: docId
              ),
            SizedBox(height: 16),
              MoveList(
                moves: pokemon['moves'].cast<String>(),
              ),
          ],
        ),
      ),
    );
  }
}