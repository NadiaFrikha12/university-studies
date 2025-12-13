abstract class Ecole{
    private String nom;
    private Etudiant []T ;
    private static final int MAX_LENGTH = 500; 
    private int nbe;

    Ecole(String name){
        nom = name;
        T = new Etudiant[MAX_LENGTH];
        nbe =0 ;
    }

    public int rechercherEtudiant(Etudiant e){
        for(int i = 0; i<nbe ; i++){
            if (T[i].equals(e)) {
                return 1;
            }
        }
        return 0;
    }
    public void ajouterEtudiant( Etudiant e){
        
        if (nbe < MAX_LENGTH){
            System.out.println("m3abya");
        }
        else {
            if (rechercherEtudiant(e) == 1){
                System.out.println("rak mawjoud fel ecole");
            }
            else{
                T[nbe] = e;
                nbe = nbe +1;
            }
        }
    }

    public float getMoyenneDes3A(){
        float somme =0;
        int nb=0;
        for(int i = 0; i<nbe ; i++){
            if ((T[i]) instanceof Etudiant3eme){
                somme += (T[i]).get_moy();
                nb +=1;
            }
        }
        if (nb != 0){
            return somme/nb;
        }
        else {
            return 0 ;
        }
    }

    public float getMoyenneDesAlternants(){
        float somme =0;
        int nb=0;
        for(int i = 0; i<nbe ; i++){
            if ((T[i]) instanceof EtudiantAlternance){
                somme += (T[i]).get_moy();
                nb +=1;
            }
        }
        if (nb != 0){
            return somme/nb;
        }
        else {
            return 0 ;
        }
    }

    @Override
    public String toString(){
         for(int i = 0; i<nbe ; i++){
            if ((T[i]) instanceof EtudiantAlternance){
                return (EtudiantAlternance.toString)
            }
        
    }
}

class Etudiant{
    protected int id;
    protected String nom;
    protected String prenom;
    protected float moy;

    Etudiant( int id, String nom, String prenom, float moy){
        this.id = id;
        this.nom = nom;
        this.prenom = prenom;
        this.moy = moy;
    }

    public int get_id(){
        return id;
    }
    public String get_nom(){
        return nom;
    }
    public String get_prenom(){
        return prenom;
    }
    public float get_moy(){
        return moy;
    }

    public void set_id(int id){
        this.id = id;
    }
    public void set_nom(String nom){
        this.nom = nom;
    }
    public void set_prenom(String prenom){
        this.prenom = prenom;
    }
    public void set_moy(float moy){
        this.moy = moy;
    }
    
    public boolean equals(Etudiant e){
        if ((this.id == e.id) & (this.nom).equals(e.nom)){
            return true;
        }
        else{
            return false;
        }
    }

    @Override
    public static String toString(){
        return ("id : " + this.get_id()+ " nom : " + this.get_nom()+ " prenom : " + this.get_prenom()+ " moy : " +this.get_moy()) ;   
    }

    public void ajouterUneAbsence(){}

}

class Etudiant3eme extends Etudiant{
    private String branche; 

    Etudiant3eme(int id, String nom, String prenom, float moy, String branche){
        super(id,nom,prenom,moy);
        this.branche = branche;
    }

    @Override
    public void ajouterUneAbsence(){
        float m = this.get_moy() - 0.5f;
        this.set_moy(m);
    }
}

class EtudiantAlternance extends Etudiant{
    private int sal;

    EtudiantAlternance(int id, String nom, String prenom, float moy, int sal){
        super(id,nom,prenom,moy);
        this.sal = sal;
    }

    @Override
    public void ajouterUneAbsence(){
        this.sal -=  50;
    }

    @Override
    public static String toString(){
        return ( super.toString() + "salaire :" + sal) ;   
    }

}


class EtudiantExisteException(){
    System.out.println("rak mawjoud");
}

public class Maiin {
    
}
