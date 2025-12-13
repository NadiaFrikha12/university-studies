public class Personne {
    private String nom;
    private String prenom;
    private String motDePasse; 

    String getNom(){
        return nom;
    }

    String getPrenom(){
        return prenom;
    }

    void verifMotDePasse(String cle) {
        if (cle.equals(motDePasse) == True){
            System.out.println("mot de passe correct");
        }
        else{
            System.out.println("mot de passe n'est pas correct");
        }
    }
    
}
