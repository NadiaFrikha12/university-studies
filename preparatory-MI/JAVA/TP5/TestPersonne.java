class Personne{
    void saluer(){
        System.out.println("Bonjour, comment ça va ?");
    }
}

class Enseignant extends Personne{

}

class EnseignantSecondaire extends Enseignant{
    void saluer(){
        System.out.println("Bonjour, comment vont mes élèves ?");
    }
}

class EnseignantUniversitaire extends Enseignant{
    void saluer(){
        System.out.println("Bonjour, comment vont mes étudiants ?");
    }
}

class TestPersonne{ 
    public static void main (String[] args){
        Personne p1 = new Personne(); 
        Personne p2 = new Enseignant();
        Personne p3 = new EnseignantSecondaire();
        EnseignantUniversitaire p4 = new EnseignantUniversitaire();
        Enseignant p5 = new EnseignantSecondaire();
        Enseignant p6 = new Enseignant();
        p1.saluer(); //Bonjour, comment ça va ?
        p2.saluer(); //Bonjour, comment ça va ?
        p3.saluer(); //Bonjour, comment vont mes élèves ?
        p4.saluer(); //Bonjour, comment vont mes étudiants ?
        p5.saluer(); //Bonjour, comment vont mes élèves ?
        p6.saluer(); //Bonjour, comment ça va ?
    }
}