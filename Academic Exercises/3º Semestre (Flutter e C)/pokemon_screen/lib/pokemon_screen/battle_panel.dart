import 'package:flutter/material.dart';
import 'package:pokemon_screen/pokemon_screen/stat_bar.dart';



class BattlePanel extends StatefulWidget {
  final int level;
  final String name;
  
  const BattlePanel({
    super.key,
    required this.level,
    required this.name
  });

  @override
  State<BattlePanel> createState() => _BattlePanelState();
}


class _BattlePanelState extends State<BattlePanel> {
  late int level;
  late int hp;
  late int hpMax;
  late int xp;
  late int xpMax;
  
  @override
  void initState() {
    super.initState();
    level = widget.level;
    hpMax = level * 2 + 20;
    hp = hpMax;
    xp = 0;
    xpMax = level * 8 + 20;
  }


  Color get corHp {
    if (hp < 30) return Colors.red;
    if (hp < 60) return Colors.yellow;
    return Colors.green;
  }
  String get msg {
    if (hp <= 0) {
      return "${widget.name} desmaiou";
    } else {
      if (hp < 30) {
        return "HP critico";
      } else {
        return "";
      }
    }
  }

  @override
  Widget build(BuildContext context) {
    return Card(
      color: const Color(0xFF38353D),
      elevation: 2,
      child: Padding(
        padding: const EdgeInsets.all(16),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Text('Nível $level', style: const TextStyle(color: Colors.white, fontSize: 20, fontWeight: FontWeight.bold)),
            const SizedBox(height: 8),
            // XP Bar
            StatBar(level: level, txt: "XP", o: xp, oMax: xpMax, cor: Colors.blue),
            const SizedBox(height: 8),
            // HP Bar
            StatBar(level: level, txt: "HP", o: hp, oMax: hpMax, cor: corHp),
            const SizedBox(height: 8),
            Text(msg, style: const TextStyle(color: Colors.red, fontSize: 14)),
            const SizedBox(height: 8),
            // Botoes
            Row(
              mainAxisSize: MainAxisSize.min,
              children: [
                ElevatedButton.icon(
                  icon: const Icon(Icons.flash_on),
                  label: const Text('Atacar'),
                  style: ElevatedButton.styleFrom(
                    backgroundColor: Colors.red.shade700,
                    foregroundColor: Colors.white,
                  ),
                  onPressed: hp > 0 ? () {
                    setState(() {
                      hp = (hp - 20).clamp(0, hpMax);
                      xp = xp + 10;
                      if (xp >= xpMax) {
                        level++;
                        hpMax = level*2+20;
                        xp = 0;
                        xpMax = level*8+20;
                      }
                    });
                  } : null
                ),
                const SizedBox(width: 12),
                ElevatedButton.icon(
                  icon: const Icon(Icons.favorite),
                  label: const Text('Usar Poção'),
                  style: ElevatedButton.styleFrom(
                    backgroundColor: Colors.green.shade700,
                    foregroundColor: Colors.white,
                  ),
                  onPressed: hp < hpMax ? () {
                    setState(() {
                      hp = (hp + 30).clamp(0, hpMax);
                    });
                  } : null
                ),
                const SizedBox(width: 12),
                ElevatedButton.icon(
                  icon: const Icon(Icons.cancel_outlined),
                  label: const Text('Encerrar Batalha'),
                  style: ElevatedButton.styleFrom(
                    backgroundColor: Color.fromARGB(255, 1, 12, 28),
                    foregroundColor: Colors.white,
                  ),
                  onPressed: () {
                    Navigator.pop(context, level);
                  }
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
}