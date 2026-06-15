/*  
Nome: Caio Lucena Andrade 
RA: 25011275
*/ 

/* Prompts usados no Gemini:

"como é a estrutura de um formulario no flutter?"
"como é um FloatingActionButton que leve para esse tela?"
*/



import 'package:flutter/material.dart';
import 'package:pokemon_screen/home_screen.dart';
import 'package:firebase_core/firebase_core.dart';
import 'firebase_options.dart'; // Arquivo gerado pelo FlutterFire CLI
import 'auth_screen.dart';
import 'package:firebase_auth/firebase_auth.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  
  await Firebase.initializeApp(
    options: DefaultFirebaseOptions.currentPlatform,
  );

  runApp(
    MaterialApp(
      debugShowCheckedModeBanner: false,
      home: StreamBuilder<User?>(
        stream: FirebaseAuth.instance.authStateChanges(),
        builder: (context, snapshot) {
          if (snapshot.connectionState == ConnectionState.waiting) {
            return const Scaffold(body: Center(child: CircularProgressIndicator()));
          }
          if (snapshot.hasData) return const HomeScreen();
          return const AuthScreen();
        },
      ),
    ),
  );
}