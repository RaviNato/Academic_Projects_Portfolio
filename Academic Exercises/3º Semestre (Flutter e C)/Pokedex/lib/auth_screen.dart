import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';

class AuthScreen extends StatefulWidget {
  const AuthScreen({super.key});

  @override
  State<AuthScreen> createState() => _AuthScreenState();
}

class _AuthScreenState extends State<AuthScreen> {
  final _formKey = GlobalKey<FormState>();
  bool _isLogin = true;
  bool _loading = false;
  String? _error;

  final _emailController = TextEditingController();
  final _passwordController = TextEditingController();

  String _mensagemErro(String code) => switch (code) {
        'invalid-email' => 'E-mail inválido.',
        'user-not-found' || 'wrong-password' || 'invalid-credential' => 'E-mail ou senha incorretos.',
        'email-already-in-use' => 'Este e-mail já está cadastrado.',
        'weak-password' => 'Senha muito fraca. Use pelo menos 6 caracteres.',
        _ => 'Erro inesperado. Tente novamente.',
      };

  Future<void> _submit() async {
    if (!_formKey.currentState!.validate()) return;
    
    setState(() {
      _loading = true;
      _error = null;
    });
    
    try {
      if (_isLogin) {
        await FirebaseAuth.instance.signInWithEmailAndPassword(
          email: _emailController.text.trim(),
          password: _passwordController.text,
        );
      } else {
        await FirebaseAuth.instance.createUserWithEmailAndPassword(
          email: _emailController.text.trim(),
          password: _passwordController.text,
        );
      }
    } on FirebaseAuthException catch (e) {
      setState(() => _error = _mensagemErro(e.code));
    } finally {
      setState(() => _loading = false);
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Color(0xFF171719),
      body: Center(
        child: SingleChildScrollView(
          padding: const EdgeInsets.all(24.0),
          child: Form(
            key: _formKey,
            child: Column(
              mainAxisSize: MainAxisSize.min,
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Container(
                  width: 80,
                  height: 80,
                  decoration: const BoxDecoration(
                    color: Color(0xFFd40c37),
                    shape: BoxShape.circle,
                  ),
                  child: const Icon(
                    Icons.catching_pokemon,
                    size: 50,
                    color:Color(0xFF171719),
                  ),
                ),
                const SizedBox(height: 24),

                Text(
                  _isLogin ? 'Liga Pokémon' : 'Registro de Treinador',
                  style: const TextStyle(
                    fontSize: 28,
                    fontWeight: FontWeight.bold,
                    color: Colors.white,
                  ),
                ),
                const SizedBox(height: 8),

                Text(
                  _isLogin
                      ? 'Entre com sua conta de treinador'
                      : 'Crie sua conta para iniciar sua jornada',
                  textAlign: TextAlign.center,
                  style: TextStyle(
                    fontSize: 16,
                    color: Colors.white,
                  ),
                ),
                const SizedBox(height: 32),

                TextFormField(
                  controller: _emailController,
                  style: const TextStyle(color: Colors.white),
                  keyboardType: TextInputType.emailAddress,
                  decoration: const InputDecoration(
                    labelText: 'E-mail',
                    labelStyle: TextStyle(color: Colors.white70),
                    border: OutlineInputBorder(),
                    prefixIcon: Icon(Icons.email, color: Colors.white70),
                  ),
                  validator: (value) {
                    if (value == null || value.trim().isEmpty) {
                      return 'O e-mail não pode ser vazio.';
                    }
                    if (!value.contains('@')) {
                      return 'Insira um e-mail válido.';
                    }
                    return null;
                  },
                ),
                const SizedBox(height: 16),

                TextFormField(
                  controller: _passwordController,
                  style: const TextStyle(color: Colors.white),
                  obscureText: true,
                  decoration: const InputDecoration(
                    labelText: 'Senha',
                    labelStyle: TextStyle(color: Colors.white70),
                    border: OutlineInputBorder(),
                    prefixIcon: Icon(Icons.lock, color: Colors.white70),
                  ),
                  validator: (value) {
                    if (value == null || value.isEmpty) {
                      return 'A senha não pode ser vazia.';
                    }
                    if (!_isLogin && value.length < 6) {
                      return 'A senha deve conter no mínimo 6 caracteres.';
                    }
                    return null;
                  },
                ),
                const SizedBox(height: 16),

                if (_error != null) ...[
                  Text(
                    _error!,
                    style: const TextStyle(color: Colors.red, fontSize: 14),
                    textAlign: TextAlign.center,
                  ),
                  const SizedBox(height: 16),
                ],

                _loading
                    ? const CircularProgressIndicator()
                    : SizedBox(
                        width: double.infinity,
                        height: 48,
                        child: FilledButton(
                          style: FilledButton.styleFrom(
                            backgroundColor: Color(0xFFd40c37),
                          ),
                          onPressed: _submit,
                          child: Text(_isLogin ? 'Entrar' : 'Cadastrar'),
                        ),
                      ),
                const SizedBox(height: 8),

                TextButton(
                  onPressed: () {
                    _formKey.currentState?.reset();
                    _emailController.clear();
                    _passwordController.clear();
                    setState(() {
                      _isLogin = !_isLogin;
                      _error = null;
                    });
                  },
                  child: Text(
                    _isLogin
                        ? 'Novo Treinador? Registrar'
                        : 'Já tem uma conta? Entrar',
                    style: const TextStyle(color: Color(0xFFd40c37))
                  ),
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }

  @override
  void dispose() {
    _emailController.dispose();
    _passwordController.dispose();
    super.dispose();
  }
}