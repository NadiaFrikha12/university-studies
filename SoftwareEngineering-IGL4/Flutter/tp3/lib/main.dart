import 'package:flutter/material.dart';

void main() =>
    runApp(const MaterialApp(debugShowCheckedModeBanner: false, home: Home()));

final categoriesConfig = {
  'alimentation': {
    'emoji': '🍽️',
    'label': 'Alimentation',
    'color': Colors.green,
  },
  'transport': {'emoji': '🚗', 'label': 'Transport', 'color': Colors.blue},
  'loisirs': {'emoji': '🎮', 'label': 'Loisirs', 'color': Colors.orange},
  'sante': {'emoji': '⚕️', 'label': 'Santé', 'color': Colors.red},
  'education': {'emoji': '📚', 'label': 'Éducation', 'color': Colors.purple},
  'autres': {'emoji': '📦', 'label': 'Autres', 'color': Colors.grey},
};

class Expense {
  final String title;
  final double amount;
  final String cat;
  Expense(this.title, this.amount, this.cat);
}

class Home extends StatefulWidget {
  const Home({super.key});
  @override
  State<Home> createState() => _HomeState();
}

class _HomeState extends State<Home> {
  final titleCtrl = TextEditingController();
  final amountCtrl = TextEditingController();
  String? cat;
  final List<Expense> expenses = [];

  double get total => expenses.fold(0, (s, e) => s + e.amount);

  void alerte(String titre, String msg) => showDialog(
    context: context,
    builder: (_) => AlertDialog(
      title: Text(titre),
      content: Text(msg),
      actions: [
        TextButton(
          onPressed: () => Navigator.pop(context),
          child: const Text('Ok'),
        ),
      ],
    ),
  );

  void ajouter() {
    final amount = double.tryParse(amountCtrl.text);
    if (titleCtrl.text.isEmpty || amount == null || cat == null) {
      alerte(
        'Erreur de saisie',
        'Veuillez remplir tous les champs (intitulé, montant et catégorie)',
      );
      return;
    }
    setState(() => expenses.add(Expense(titleCtrl.text, amount, cat!)));
    reinitialiser();
  }

  void reinitialiser() {
    setState(() {
      titleCtrl.clear();
      amountCtrl.clear();
      cat = null;
    });
  }

  void choisirCategorie() => showDialog(
    context: context,
    builder: (_) => SimpleDialog(
      title: const Text('Catégorie'),
      children: categoriesConfig.entries
          .map(
            (e) => SimpleDialogOption(
              onPressed: () {
                setState(() => cat = e.key);
                Navigator.pop(context);
              },
              child: Text('${e.value['emoji']} ${e.value['label']}'),
            ),
          )
          .toList(),
    ),
  );

  void supprimer(Expense e) => showDialog(
    context: context,
    builder: (_) => SimpleDialog(
      title: const Text('Supprimer une dépense'),
      children: [
        SimpleDialogOption(
          onPressed: () {
            setState(() => expenses.remove(e));
            Navigator.pop(context);
          },
          child: const Text('Supprimer cette dépense'),
        ),
        SimpleDialogOption(
          onPressed: () {
            setState(() => expenses.clear());
            Navigator.pop(context);
          },
          child: const Text('Supprimer toutes les dépenses'),
        ),
        SimpleDialogOption(
          onPressed: () => Navigator.pop(context),
          child: const Text('Annuler'),
        ),
      ],
    ),
  );

  @override
  void dispose() {
    titleCtrl.dispose();
    amountCtrl.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Gestionnaire de dépenses'),
        backgroundColor: Colors.blue[800],
        foregroundColor: Colors.white,
      ),
      body: Padding(
        padding: const EdgeInsets.all(16),
        child: Column(
          children: [
            Card(
              child: Padding(
                padding: const EdgeInsets.all(16),
                child: Column(
                  children: [
                    const Text(
                      'Nouvelle dépense',
                      style: TextStyle(
                        fontSize: 22,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                    TextField(
                      controller: titleCtrl,
                      decoration: const InputDecoration(labelText: 'Intitulé'),
                    ),
                    TextField(
                      controller: amountCtrl,
                      keyboardType: TextInputType.number,
                      decoration: const InputDecoration(labelText: 'Montant'),
                    ),
                    ListTile(
                      contentPadding: EdgeInsets.zero,
                      title: Text(
                        cat == null
                            ? 'Sélectionnez une catégorie'
                            : '${categoriesConfig[cat]!['emoji']} ${categoriesConfig[cat]!['label']}',
                      ),
                      trailing: const Icon(Icons.unfold_more),
                      onTap: choisirCategorie,
                    ),
                    Row(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        OutlinedButton.icon(
                          onPressed: ajouter,
                          icon: const Icon(Icons.add),
                          label: const Text('Ajouter'),
                        ),
                        const SizedBox(width: 8),
                        OutlinedButton.icon(
                          onPressed: reinitialiser,
                          style: OutlinedButton.styleFrom(
                            foregroundColor: Colors.red,
                          ),
                          icon: const Icon(Icons.close),
                          label: const Text('Réinitialiser'),
                        ),
                      ],
                    ),
                  ],
                ),
              ),
            ),
            Expanded(
              child: expenses.isEmpty
                  ? const Center(child: Text('Aucune dépense enregistrée'))
                  : ListView(
                      children: expenses.map((e) {
                        final c = categoriesConfig[e.cat]!;
                        return ListTile(
                          leading: Chip(
                            label: Text(
                              '${c['emoji']} ${c['label']}',
                              style: const TextStyle(
                                color: Colors.white,
                                fontSize: 12,
                              ),
                            ),
                            backgroundColor: c['color'] as Color,
                          ),
                          title: Text('${e.title} : ${e.amount}€'),
                          trailing: IconButton(
                            icon: const Icon(Icons.close, color: Colors.red),
                            onPressed: () => supprimer(e),
                          ),
                        );
                      }).toList(),
                    ),
            ),
            Text(
              'Total des dépenses : $total€',
              style: const TextStyle(fontWeight: FontWeight.bold),
            ),
          ],
        ),
      ),
    );
  }
}
