import 'package:flutter/material.dart';

class PokemonCard extends StatelessWidget {
  final String name;
  final String spriteUrl;
  final List<String> types;


  

  const PokemonCard({
    super.key,
    required this.name,
    required this.spriteUrl,
    required this.types
  });
  

  @override
  Widget build(BuildContext context) {
    return Card(
      color: Color(0xFF38353D),
      elevation: 2,
      child: Padding(
        padding: const EdgeInsets.all(16),
        child: Row(
          children: [
            CircleAvatar(
              radius: 30,
              backgroundColor: Colors.indigo.shade100,
              backgroundImage: NetworkImage(spriteUrl),
            ),

            SizedBox(width: 16),

            Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Text(name, style: const TextStyle(color: Colors.white, fontSize: 20, fontWeight: FontWeight.bold)),
                Row(
                  children: [
                    for (var typeId in types) ...{
                      Image.network(
                        'https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/types/generation-iii/firered-leafgreen/$typeId.png', 
                        height: 12,
                      ),
                      SizedBox(width: 4)
                    },
                  ],
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
}