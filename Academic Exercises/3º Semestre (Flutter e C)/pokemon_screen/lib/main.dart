/*  
Nome: Caio Lucena Andrade 
RA: 25011275
*/ 

/* Prompts usados no Gemini:

"preciso separar os botoes e a msg em uma classe diferente, sem usar nada de muito diferente",
"na pokemonScreen consigo chamar o pokemon.name?",
*/



import 'package:flutter/material.dart';
import 'package:pokemon_screen/home_screen.dart';

void main() {
  runApp(const MaterialApp(
    debugShowCheckedModeBanner: false,
    home: HomeScreen(),
  ));
}