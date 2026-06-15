import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/material.dart';
import 'package:pokemon_screen/pokemon_screen.dart';
import 'new_pokemon_screen.dart';
import 'package:pokemon_screen/trainer_profile_screen.dart';
import 'package:firebase_auth/firebase_auth.dart';

final collection = FirebaseFirestore.instance.collection('pokemons');

class HomeScreen extends StatefulWidget {
  const HomeScreen({super.key});

  @override
  State<HomeScreen> createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {


  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Color(0xFF171719),
      appBar: AppBar(
        title: Column(
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            const Text('Pokedex', style: TextStyle(fontSize: 18)),
            Text(
              FirebaseAuth.instance.currentUser?.email ?? '',
              style: const TextStyle(fontSize: 12, fontWeight: FontWeight.normal),
            ),
          ],
        ),
        backgroundColor: const Color.fromARGB(255, 212, 12, 55),
        foregroundColor: Colors.white,
        centerTitle: true,
        actions: [
          IconButton(
            icon: const Icon(Icons.logout),
            onPressed: () => FirebaseAuth.instance.signOut(),
          ),
          FutureBuilder<DocumentSnapshot<Map<String, dynamic>>>(
            future: FirebaseFirestore.instance
                .collection('config')
                .doc('treinador')
                .get(),
            builder: (context, snapshot) {
              // Ícone padrão de fallback enquanto carrega ou se não houver dados
              Widget avatarWidget = const Icon(Icons.person);

              if (snapshot.hasData && snapshot.data!.exists) {
                final data = snapshot.data!.data();
                if (data != null && data['avatarIndex'] != null) {
                  final int index = data['avatarIndex'] as int;
                  
                  // Substitui o ícone pela imagem do avatar estilizada em um círculo
                  avatarWidget = ClipOval(
                    child: Image.asset(
                      'assets/trainers/trainer_${index+1}.png',
                      width: 32,
                      height: 32,
                      fit: BoxFit.cover,
                      // Caso a imagem falhe por algum motivo, volta para o ícone padrão
                      errorBuilder: (context, error, stackTrace) => const Icon(Icons.person),
                    ),
                  );
                }
              }

              return Padding(
                padding: const EdgeInsets.only(right: 8.0),
                child: IconButton(
                  icon: avatarWidget,
                  tooltip: 'Alterar Avatar',
                  onPressed: () async {
                    // Aguarda o retorno da tela de perfil
                    await Navigator.push(
                      context,
                      MaterialPageRoute(
                        builder: (context) => const TrainerProfileScreen(),
                      ),
                    );
                    // Quando o usuário voltar da TrainerProfileScreen, 
                    // este setState força a HomeScreen a atualizar e recarregar o FutureBuilder
                    setState(() {});
                  },
                ),
              );
            },
          ),
        ],
      ),
      
      body: StreamBuilder(
        stream: collection.snapshots(),
        builder: (context, snapshot) {
          if (!snapshot.hasData) return const Center(child: CircularProgressIndicator());
          final docs = snapshot.data!.docs;
          return ListView.builder(
            itemCount: docs.length,
            itemBuilder: (context, index) {
              final pokemondata = docs[index].data();
              final docId = docs[index].id;

              return Stack(
                clipBehavior: Clip.none, // Permite que o botão saia da borda
                children: [
                  Card(
                    color: Color(0xFF38353D),
                    margin: const EdgeInsets.symmetric(horizontal: 10, vertical: 10),
                    child: ListTile(
                      leading: CircleAvatar(
                        backgroundColor: Colors.indigo.shade100,
                        backgroundImage: NetworkImage(pokemondata['spriteUrl'] as String), 
                      ),

                      title: Text(
                        pokemondata['name'],
                        style: const TextStyle(color: Colors.white, fontWeight: FontWeight.bold),
                      ),

                      subtitle: Text('Nível ${pokemondata['level']}', style: TextStyle(color: Colors.white)),

                      trailing: const Icon(Icons.chevron_right),

                      onTap:() async {
                        final int? novoNivel = await Navigator.push<int>(
                          context,
                          MaterialPageRoute(builder: (context) => PokemonScreen(pokemon: pokemondata, docId: docId)),
                        );

                        if (novoNivel != null) {
                          setState(() {
                            pokemondata['level'] = novoNivel;
                          });
                        }
                      },
                    ),
                  ),
                  Positioned(
                    bottom: -10, // Move o botão para cima da borda superior
                    right: -10, // Move o botão para fora da borda lateral
                    child: IconButton(
                      icon: Icon(Icons.delete, color: Colors.indigo.shade100, size: 25),
                      onPressed: () async {
                        await collection.doc(docId).delete();
                      },
                    ),
                  ),
                ],
              );
            },
          );
        },
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          Navigator.push(
            context,
            MaterialPageRoute(builder: (context) => const NewPokemonScreen()),
          );
        },
        backgroundColor: Color.fromARGB(255, 212, 12, 55),
        child: const Icon(Icons.add, color: Colors.white),
      ),
    );
  }
}