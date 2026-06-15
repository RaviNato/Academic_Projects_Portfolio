import 'package:flutter/material.dart';

class StatBar extends StatelessWidget {
  final int level;
  final String txt;
  final int o;
  final int oMax;
  final Color cor;


  const StatBar({
    super.key,
    required this.level,
    required this.txt,
    required this.o,
    required this.oMax,
    required this.cor
  });



  @override
  Widget build(BuildContext context) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Text('$txt: $o / $oMax', style: TextStyle(color: cor, fontSize: 14)),
        ClipRRect(
          borderRadius: const BorderRadius.all(Radius.circular(10)),
          child: LinearProgressIndicator(
            value: o / oMax,
            backgroundColor: const Color(0xFF171719),
            color: cor,
            minHeight: 8,
          ),
        ),
      ],
    );
  }
}