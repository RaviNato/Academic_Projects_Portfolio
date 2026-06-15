# Pokédex - Tecnologia e Programação para Dispositivos Móveis

Este projeto foi desenvolvido ao longo de várias aulas na PUCC (Pontifícia Universidade Católica de Campinas) dentro do curso de Sistemas de Informação, especificamente para a matéria de Tecnologia e Programação para Dispositivos Móveis.

O aplicativo consiste em uma Pokédex personalizada com gerenciamento de treinadores e evolução de criaturas, integrada a uma API externa para consumo de dados e uma base de dados para persistência.

## Funcionalidades do Projeto

* **Autenticação de Usuários:** Tela de login estruturada com validação de e-mail e senha.
* **Painel Principal (Home):** Exibição da lista de Pokémon capturados pelo usuário autenticado, apresentando os respectivos nomes e níveis atuais de cada um.
* **Gerenciamento de Pokémons:** Opção para adicionar novos Pokémon à lista pessoal sem limitação de quantidade, buscando as informações diretamente de uma API de Pokédex.
* **Mecanismo de Treino:** Interface interna de cada Pokémon que permite ao usuário interagir e treinar a criatura, incrementando o seu nível diretamente no banco de dados.

## Execução do Projeto

Para inicializar e testar o projeto localmente, execute os comandos abaixo no diretório raiz:

npm install
flutter run -d edge
