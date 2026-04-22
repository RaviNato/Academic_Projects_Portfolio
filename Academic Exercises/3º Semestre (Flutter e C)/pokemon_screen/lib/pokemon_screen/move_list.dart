import 'package:flutter/material.dart';

class MoveList extends StatelessWidget {
  final List<String> moves;

  const MoveList({
    super.key,
    required this.moves
  });
  
  
  @override
  Widget build(BuildContext context) {
    return Card(
      color: Color(0xFF38353D),
      elevation: 2,
      child: Padding(
        padding: const EdgeInsets.all(16),
        child:Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                const Text('Golpes', style: TextStyle(color: Colors.white, fontSize: 20, fontWeight: FontWeight.bold)),
                Row(
                  children: [
                    //Icon(icon1, color: iconColor, size: 18),
                    const SizedBox(width: 4),
                    Text(moves[0], style: const TextStyle(color: Colors.grey, fontSize: 14)),
                  ],
                ),
                Row(
                  children: [
                    //Icon(icon2, color: iconColor, size: 18),
                    const SizedBox(width: 4),
                    Text(moves[1], style: const TextStyle(color: Colors.grey, fontSize: 14)),
                  ],
                ),
                Row(
                  children: [
                    //Icon(icon3, color: iconColor, size: 18),
                    const SizedBox(width: 4),
                    Text(moves[2], style: const TextStyle(color: Colors.grey, fontSize: 14)),
                  ],
                ),
                Row(
                  children: [
                    //Icon(icon4, color: iconColor, size: 18),
                    const SizedBox(width: 4),
                    Text(moves[3], style: const TextStyle(color: Colors.grey, fontSize: 14)),
                  ],
                ),
             ],
           ),
        ),
     );
  }
}