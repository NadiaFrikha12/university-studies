class Personne{
    protected String nom; 

    Personne (String name){
        nom = name;
    }

    public void affiche(){
        System.out.println(" je suis " + nom);
    }

}

class Forgeron extends Personne{

    Forgeron (String name){
        super(name);
    }

    @Override
    public void affiche(){
        System.out.println(" je suis " + nom + " le forgeron");
    } 
}

class Menuisier extends Personne{
    Menuisier (String name){
        super(name);
    }

    @Override
    public void affiche(){
        System.out.println(" je suis " + nom + " le Menuisier");
    } 
}

public class TestMetiers {
    public static void main(String[] args) {
        Personne[] personnes = new Personne[4];
        personnes[0] =new Personne("SALAH");
        personnes[1] =new Forgeron("ALI");
        personnes[2] =new Menuisier("MOHAMED");
        personnes[3] =new Forgeron("AMOR");

        for(int i=0 ; i<personnes.length ; i++){
            personnes[i].affiche();
        }
    }
}
