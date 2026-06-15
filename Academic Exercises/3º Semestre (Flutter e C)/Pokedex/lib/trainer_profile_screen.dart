import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';

class TrainerProfileScreen extends StatefulWidget {
  const TrainerProfileScreen({super.key});

  @override
  State<TrainerProfileScreen> createState() => _TrainerProfileScreenState();
}

class _TrainerProfileScreenState extends State<TrainerProfileScreen> {

  final _formKey = GlobalKey<FormState>();
  final TextEditingController _nameController = TextEditingController();
  
  int _selectedAvatar = 0;
  bool _isLoading = false;

  @override
  void initState() {
    super.initState();
    _loadProfile();
  }

  Future<void> _loadProfile() async {
    final doc = await FirebaseFirestore.instance
        .collection('config')
        .doc('treinador')
        .get();
        
    if (doc.exists && doc.data() != null) {
      final data = doc.data()!;
      setState(() {
        _nameController.text = data['name'] as String? ?? '';
        _selectedAvatar = data['avatarIndex'] as int? ?? 0;
      });
    }
  }

  Future<void> _saveProfile() async {
    if (!_formKey.currentState!.validate()) return;

    setState(() {_isLoading = true;});

    try {
      await FirebaseFirestore.instance
          .collection('config')
          .doc('treinador')
          .set({
            'name': _nameController.text.trim(),
            'avatarIndex': _selectedAvatar,
          }, SetOptions(merge: true));

      if (!mounted) return;

      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text('Perfil salvo!', textAlign: TextAlign.center),
          backgroundColor: Colors.green,
        ),
      );

      Navigator.pop(context);

    } finally {
      if (mounted) {
        setState(() {
          _isLoading = false;
        });
      }
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: const Color(0xFF171719),
      appBar: AppBar(
        title: const Text('Selecionar avatar'),
        backgroundColor: const Color.fromARGB(255, 212, 12, 55),
        foregroundColor: Colors.white,
      ),
      body: SingleChildScrollView(
        padding: const EdgeInsets.all(16.0),
        child: Form(
          key: _formKey,
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.stretch,
            children: [
              TextFormField(
                controller: _nameController,
                style: const TextStyle(color: Colors.white),
                decoration: const InputDecoration(
                  labelText: 'Nome do Treinador',
                  border: OutlineInputBorder(),
                  labelStyle: TextStyle(color: Colors.grey),
                ),
                validator: (value) {
                  if (value == null || value.trim().length < 2) {
                    return 'O nome deve ter no mínimo 2 caracteres';
                  }
                  return null;
                },
              ),
              
              const Padding(
                padding: EdgeInsets.symmetric(vertical: 24.0),
                child: Text(
                  'Selecione seu Avatar:',
                  style: TextStyle(color: Colors.white, fontSize: 16, fontWeight: FontWeight.bold),
                ),
              ),

              GridView.count(
                crossAxisCount: 3,
                shrinkWrap: true,
                physics: const NeverScrollableScrollPhysics(), // Impede conflito de scroll
                children: List.generate(6, (i) {
                  final isSelected = _selectedAvatar == i;
                  return GestureDetector(
                    onTap: () => setState(() => _selectedAvatar = i),
                    child: Container(
                      margin: const EdgeInsets.all(8),
                      decoration: BoxDecoration(
                        color: isSelected ? Color(0xFF6850a3).withOpacity(0.2) : Colors.transparent,
                        border: Border.all(
                          color: isSelected ? Color(0xFF6850a3) : Colors.grey.withOpacity(0.3),
                          width: 3,
                        ),
                        borderRadius: BorderRadius.circular(12),
                      ),
                      child: Padding(
                        padding: const EdgeInsets.all(8.0),

                        child: Image.asset(
                          'assets/trainers/trainer_${i+1}.png',
                          fit: BoxFit.contain,
                        ),
                      ),
                    ),
                  );
                }),
              ),

              const SizedBox(height: 32),

              ElevatedButton(
                onPressed: _isLoading ? null : _saveProfile,
                style: ElevatedButton.styleFrom(
                  backgroundColor: const Color.fromARGB(255, 212, 12, 55),
                  foregroundColor: Colors.white,
                  padding: const EdgeInsets.symmetric(vertical: 16),
                  shape: RoundedRectangleBorder(
                    borderRadius: BorderRadius.circular(8),
                  ),
                ),
                child: _isLoading
                    ? const SizedBox(
                        height: 20,
                        width: 20,
                        child: CircularProgressIndicator(
                          color: Colors.white,
                          strokeWidth: 2,
                        ),
                      )
                    : const Text(
                        'Salvar Perfil',
                        style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
                      ),
              ),
            ],
          ),
        ),
      ),
    );
  }


  @override
  void dispose() {
    _nameController.dispose();
    super.dispose();
  }
}