import 'dart:io';

import 'package:flutter/material.dart';
import 'package:image_picker/image_picker.dart';

void main() => runApp(const MyApp());

class Course {
  final int id;
  final String iconUrl;
  final String title;
  final String author;
  final List<String> keywords;

  /// URLs (cours de démo) ou chemins de fichiers (galerie / caméra).
  final List<String> images;

  Course({
    required this.id,
    required this.iconUrl,
    required this.title,
    this.author = '',
    this.keywords = const [],
    this.images = const [],
  });
}

class CourseRepository {
  CourseRepository._();

  static int _nextId = 5;

  static final List<Course> _courses = [
    Course(
      id: 1,
      title: 'Angular',
      author: 'Google',
      iconUrl: 'https://angular.dev/assets/icons/apple-touch-icon.png',
      keywords: ['typescript', 'spa', 'components', 'rxjs'],
    ),
    Course(
      id: 2,
      title: 'Android',
      author: 'Google',
      iconUrl: 'https://upload.wikimedia.org/wikipedia/commons/thumb/d/d7/Android_robot.svg/200px-Android_robot.svg.png',
      keywords: ['kotlin', 'java', 'mobile'],
    ),
    Course(
      id: 3,
      title: 'Ionic',
      author: 'Ionic Team',
      iconUrl: 'https://upload.wikimedia.org/wikipedia/commons/thumb/d/d1/Ionic_Logo.svg/200px-Ionic_Logo.svg.png',
      keywords: ['hybrid', 'angular', 'capacitor'],
    ),
    Course(
      id: 4,
      title: 'Nest JS',
      author: 'Bart Simpson',
      iconUrl: 'https://upload.wikimedia.org/wikipedia/commons/thumb/a/a8/NestJS.svg/200px-NestJS.svg.png',
      keywords: ['backend', 'api', 'node', 'rest', 'typescript'],
    ),
  ];

  static List<Course> get all => List.unmodifiable(_courses);

  static Course? byId(int id) {
    for (final c in _courses) {
      if (c.id == id) return c;
    }
    return null;
  }

  static Course add({
    required String title,
    required String author,
    required String iconUrl,
    required List<String> keywords,
    required List<String> images,
  }) {
    final course = Course(
      id: _nextId++,
      title: title,
      author: author,
      iconUrl: iconUrl,
      keywords: keywords,
      images: images,
    );
    _courses.add(course);
    return course;
  }

  static void remove(int id) => _courses.removeWhere((c) => c.id == id);
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  static const routeHome = '/';
  static const routeDetails = '/details';
  static const routeAdd = '/add';

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Our Catalog',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.blue),
        useMaterial3: true,
      ),
      initialRoute: routeHome,
      // La route "details" reçoit l'id du cours dans ses arguments.
      onGenerateRoute: (settings) {
        switch (settings.name) {
          case routeHome:
            return MaterialPageRoute(builder: (_) => const CoursesPage());
          case routeDetails:
            final id = settings.arguments as int;
            return MaterialPageRoute(
              builder: (_) => CourseDetailsPage(courseId: id),
            );
          case routeAdd:
            return MaterialPageRoute(builder: (_) => const AddCoursePage());
        }
        return null;
      },
    );
  }
}

class CourseImage extends StatelessWidget {
  final String source;
  final BoxFit fit;

  const CourseImage({super.key, required this.source, this.fit = BoxFit.cover});

  @override
  Widget build(BuildContext context) {
    const fallback = Center(
      child: Icon(Icons.broken_image_outlined, color: Colors.grey),
    );
    if (source.startsWith('http')) {
      return Image.network(
        source,
        fit: fit,
        errorBuilder: (_, __, ___) => fallback,
        loadingBuilder: (context, child, progress) => progress == null
            ? child
            : const Center(child: CircularProgressIndicator(strokeWidth: 2)),
      );
    }
    return Image.file(
      File(source),
      fit: fit,
      errorBuilder: (_, __, ___) => fallback,
    );
  }
}

//  INTERFACE 1 : liste des cours
class CoursesPage extends StatefulWidget {
  const CoursesPage({super.key});

  @override
  State<CoursesPage> createState() => _CoursesPageState();
}

class _CoursesPageState extends State<CoursesPage> {
  Future<void> _openDetails(int id) async {
    await Navigator.pushNamed(context, MyApp.routeDetails, arguments: id);
    // Au retour (suppression éventuelle), on rafraîchit la liste.
    if (mounted)
      setState(
        () {},
      ); //vérifie que le widget existe toujours dans l'arbre de l'interface
  }

  Future<void> _openAdd() async {
    final added = await Navigator.pushNamed(context, MyApp.routeAdd);
    if (!mounted) return;
    setState(() {});
    if (added == true) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text('Cours créé avec succès!'),
          backgroundColor: Colors.green,
          behavior: SnackBarBehavior.floating,
        ),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    final courses = CourseRepository.all;
    return Scaffold(
      appBar: AppBar(
        title: const Text('Our Catalog'),
        centerTitle: true,
        backgroundColor: Colors.blue,
        foregroundColor: Colors.white,
        actions: [
          IconButton(
            icon: const Icon(Icons.add),
            tooltip: 'Ajouter un cours',
            onPressed: _openAdd,
          ),
        ],
      ),
      body: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          const Padding(
            padding: EdgeInsets.fromLTRB(16, 12, 16, 8),
            child: Text(
              'We propose these new courses :',
              style: TextStyle(fontWeight: FontWeight.bold),
            ),
          ),
          Expanded(
            child: ListView.separated(
              itemCount: courses.length,
              separatorBuilder: (_, __) => const Divider(height: 1),
              itemBuilder: (context, index) {
                final c = courses[index];
                return ListTile(
                  leading: SizedBox(
                    width: 36,
                    height: 36,
                    child: CourseImage(source: c.iconUrl, fit: BoxFit.contain),
                  ),
                  title: Text(c.title),
                  trailing: const Icon(Icons.chevron_right),
                  onTap: () => _openDetails(c.id),
                );
              },
            ),
          ),
        ],
      ),
    );
  }
}

//  INTERFACE 2 : détails d'un cours (via l'id de la route)
class CourseDetailsPage extends StatelessWidget {
  final int courseId;
  const CourseDetailsPage({super.key, required this.courseId});

  Future<void> _confirmDelete(BuildContext context, Course course) async {
    final ok = await showDialog<bool>(
      context: context,
      builder: (ctx) => AlertDialog(
        title: const Text('Confirmation'),
        content: Text(
          'Voulez-vous vraiment supprimer le cours "${course.title}" ?',
        ),
        actions: [
          TextButton(
            onPressed: () => Navigator.pop(ctx, false),
            child: const Text('Annuler'),
          ),
          TextButton(
            onPressed: () => Navigator.pop(ctx, true),
            child: const Text('Supprimer', style: TextStyle(color: Colors.red)),
          ),
        ],
      ),
    );
    if (ok == true) {
      CourseRepository.remove(course.id);
      if (context.mounted) Navigator.pop(context, true);
    }
  }

  @override
  Widget build(BuildContext context) {
    final course = CourseRepository.byId(courseId);
    if (course == null) {
      return Scaffold(
        appBar: AppBar(title: const Text('Details')),
        body: const Center(child: Text('Cours introuvable')),
      );
    }

    return Scaffold(
      appBar: AppBar(
        title: const Text('Details'),
        centerTitle: true,
        backgroundColor: Colors.blue,
        foregroundColor: Colors.white,
        actions: [
          IconButton(
            icon: const Icon(Icons.delete_outline),
            tooltip: 'Supprimer',
            onPressed: () => _confirmDelete(context, course),
          ),
        ],
      ),
      body: ListView(
        padding: const EdgeInsets.all(16),
        children: [
          const _SectionTitle('Details of this course'),
          const SizedBox(height: 12),
          Center(
            child: SizedBox(
              width: 160,
              height: 160,
              child: CourseImage(source: course.iconUrl, fit: BoxFit.contain),
            ),
          ),
          const SizedBox(height: 16),
          Center(
            child: Text(
              course.author.isEmpty
                  ? course.title
                  : '${course.title} By ${course.author}',
              style: const TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
            ),
          ),
          const SizedBox(height: 20),
          const _SectionTitle('Content of this course'),
          for (final k in course.keywords)
            Container(
              width: double.infinity,
              padding: const EdgeInsets.symmetric(vertical: 12, horizontal: 8),
              decoration: BoxDecoration(
                border: Border(bottom: BorderSide(color: Colors.grey.shade300)),
              ),
              child: Text(k),
            ),
          if (course.images.isNotEmpty) ...[
            const SizedBox(height: 20),
            const _SectionTitle('Images about this course'),
            const SizedBox(height: 8),
            GridView.count(
              crossAxisCount: 2,
              shrinkWrap: true,
              physics: const NeverScrollableScrollPhysics(),
              mainAxisSpacing: 8,
              crossAxisSpacing: 8,
              children: [
                for (final img in course.images) CourseImage(source: img),
              ],
            ),
          ],
        ],
      ),
    );
  }
}

class _SectionTitle extends StatelessWidget {
  final String text;
  const _SectionTitle(this.text);

  @override
  Widget build(BuildContext context) =>
      Text(text, style: const TextStyle(fontWeight: FontWeight.bold));
}

//  INTERFACE 3 : ajout d'un cours
class AddCoursePage extends StatefulWidget {
  const AddCoursePage({super.key});

  @override
  State<AddCoursePage> createState() => _AddCoursePageState();
}

class _AddCoursePageState extends State<AddCoursePage> {
  final _formKey = GlobalKey<FormState>();
  final _titleCtrl = TextEditingController();
  final _authorCtrl = TextEditingController();
  final _urlCtrl = TextEditingController();
  final _keywordCtrl = TextEditingController();
  final _picker = ImagePicker();

  final List<String> _keywords = [];
  final List<String> _images = [];

  @override
  void dispose() {
    _titleCtrl.dispose();
    _authorCtrl.dispose();
    _urlCtrl.dispose();
    _keywordCtrl.dispose();
    super.dispose();
  }

  // ---- Mots-clés : un "espace" transforme le mot saisi en chip ----
  void _onKeywordChanged(String value) {
    if (value.endsWith(' ')) _addKeyword(value);
  }

  void _addKeyword(String raw) {
    final word = raw.trim();
    if (word.isNotEmpty && !_keywords.contains(word)) {
      setState(() => _keywords.add(word));
    }
    _keywordCtrl.clear();
  }

  // ---- Images : galerie ou caméra ----
  Future<void> _pickImage(ImageSource source) async {
    try {
      final file = await _picker.pickImage(source: source, imageQuality: 80);
      if (file != null) setState(() => _images.add(file.path));
    } catch (e) {
      if (!mounted) return;
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text("Impossible de récupérer l'image : $e")),
      );
    }
  }

  void _save() {
    // Un éventuel mot-clé en cours de saisie est pris en compte.
    if (_keywordCtrl.text.trim().isNotEmpty) _addKeyword(_keywordCtrl.text);

    if (!_formKey.currentState!.validate()) return;

    CourseRepository.add(
      title: _titleCtrl.text.trim(),
      author: _authorCtrl.text.trim(),
      iconUrl: _urlCtrl.text.trim(),
      keywords: List.of(_keywords),
      images: List.of(_images),
    );
    // On renvoie "true" à la page précédente (Navigator.pop avec donnée).
    Navigator.pop(context, true);
  }

  String? _required(String? v) =>
      (v == null || v.trim().isEmpty) ? 'Champ obligatoire' : null;

  String? _validateUrl(String? v) {
    if (v == null || v.trim().isEmpty) return 'Champ obligatoire';
    final uri = Uri.tryParse(v.trim());
    if (uri == null || !uri.hasScheme || !uri.hasAuthority) {
      return 'URL invalide';
    }
    return null;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Ajouter un cours'),
        centerTitle: true,
        backgroundColor: Colors.blue,
        foregroundColor: Colors.white,
        actions: [
          IconButton(
            icon: const Icon(Icons.check),
            tooltip: 'Enregistrer',
            onPressed: _save,
          ),
        ],
      ),
      body: Form(
        key: _formKey,
        child: ListView(
          padding: const EdgeInsets.all(16),
          children: [
            _card(
              title: 'Informations du cours',
              children: [
                TextFormField(
                  controller: _titleCtrl,
                  decoration: const InputDecoration(
                    labelText: 'Titre du cours *',
                  ),
                  validator: _required,
                ),
                TextFormField(
                  controller: _authorCtrl,
                  decoration: const InputDecoration(labelText: 'Auteur *'),
                  validator: _required,
                ),
                TextFormField(
                  controller: _urlCtrl,
                  keyboardType: TextInputType.url,
                  decoration: const InputDecoration(
                    labelText: "URL de l'image principale *",
                  ),
                  validator: _validateUrl,
                  onChanged: (_) => setState(() {}), // met à jour l'aperçu
                ),
                const SizedBox(height: 12),
                if (_urlCtrl.text.trim().startsWith('http'))
                  Center(
                    child: Container(
                      width: 120,
                      height: 120,
                      color: Colors.grey.shade200,
                      child: CourseImage(
                        source: _urlCtrl.text.trim(),
                        fit: BoxFit.contain,
                      ),
                    ),
                  ),
              ],
            ),
            const SizedBox(height: 16),
            _card(
              title: 'Mots-clés',
              children: [
                TextField(
                  controller: _keywordCtrl,
                  onChanged: _onKeywordChanged,
                  onSubmitted: _addKeyword,
                  decoration: InputDecoration(
                    labelText: 'Ajouter un mot-clé',
                    hintText: 'Ex: component',
                    suffixIcon: IconButton(
                      icon: const Icon(Icons.add),
                      onPressed: () => _addKeyword(_keywordCtrl.text),
                    ),
                  ),
                ),
                const SizedBox(height: 12),
                Wrap(
                  spacing: 8,
                  runSpacing: 4,
                  children: [
                    for (final k in _keywords)
                      InputChip(
                        label: Text(k),
                        // Clic sur le chip OU sur la croix : suppression.
                        onPressed: () => setState(() => _keywords.remove(k)),
                        onDeleted: () => setState(() => _keywords.remove(k)),
                      ),
                  ],
                ),
              ],
            ),
            const SizedBox(height: 16),
            _card(
              title: 'Images du cours',
              children: [
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: [
                    OutlinedButton.icon(
                      onPressed: () => _pickImage(ImageSource.gallery),
                      icon: const Icon(Icons.photo_library_outlined),
                      label: const Text('Galerie'),
                    ),
                    OutlinedButton.icon(
                      onPressed: () => _pickImage(ImageSource.camera),
                      icon: const Icon(Icons.photo_camera_outlined),
                      label: const Text('Caméra'),
                    ),
                  ],
                ),
                const SizedBox(height: 12),
                if (_images.isNotEmpty)
                  GridView.count(
                    crossAxisCount: 3,
                    shrinkWrap: true,
                    physics: const NeverScrollableScrollPhysics(),
                    mainAxisSpacing: 8,
                    crossAxisSpacing: 8,
                    children: [
                      for (final path in _images)
                        Stack(
                          fit: StackFit.expand,
                          children: [
                            CourseImage(source: path),
                            Positioned(
                              top: 0,
                              right: 0,
                              child: InkWell(
                                onTap: () =>
                                    setState(() => _images.remove(path)),
                                child: const CircleAvatar(
                                  radius: 12,
                                  backgroundColor: Colors.red,
                                  child: Icon(
                                    Icons.close,
                                    size: 14,
                                    color: Colors.white,
                                  ),
                                ),
                              ),
                            ),
                          ],
                        ),
                    ],
                  ),
              ],
            ),
            const SizedBox(height: 24),
            FilledButton.icon(
              onPressed: _save,
              icon: const Icon(Icons.save),
              label: const Text('Enregistrer le cours'),
            ),
          ],
        ),
      ),
    );
  }

  Widget _card({required String title, required List<Widget> children}) {
    return Card(
      elevation: 2,
      child: Padding(
        padding: const EdgeInsets.all(16),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Text(
              title,
              style: const TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
            ),
            const SizedBox(height: 8),
            ...children,
          ],
        ),
      ),
    );
  }
}
