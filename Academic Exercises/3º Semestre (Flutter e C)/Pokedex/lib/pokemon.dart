class Pokemon {
  final String name;
  final int spriteId;
  final List<int> typeIds;
  int level;
  final List<String> moves;
  final String spriteUrl;

  Pokemon({
    required this.name,
    required this.spriteId,
    required this.typeIds,
    required this.level,
    this.moves = const [],
    required this.spriteUrl
  });
}
