class Ecole{
    private String nom;
    private int nbe;
    private static final int MAX_ETUDIANT = 500;
    private Etudiant[] T; 

    Ecole(String n){
        nom = n;
        nbe=0;
        T = new Etudiant[MAX_ETUDIANT];
    }

    public String getNom() {
        return nom;
    }
    public void setNom(String nom) {
        this.nom = nom;
    }
    public Etudiant[] getEtudiants() {
        return T;
    }
    public void setEtudiants(Etudiant[] etudiants) {
        this.T = etudiants;
    }
    public int getNombreEtudiants() {
        return nbe;
    }
    public void setNombreEtudiants(int nombreEtudiants) {
        this.nbe = nombreEtudiants;
    }

    public void ajouterEtudiant(Etudiant etudiant) throws EtudiantExisteException {
        if (rechercherEtudiant(etudiant) != -1) {
            throw new EtudiantExisteException("mawjoud");
        }
        if (nbe < MAX_ETUDIANT) {
            T[nbe] = etudiant;
            nbe++;
        }
        else{
            System.out.println("m3abya");
        }
    }
    public int rechercherEtudiant (Etudiant e){
        for(int i=0 ; i<nbe; i++){
            if (T[i].equals(e)){
                return i;
            }  
        }
        return (-1);
        
    }


    public float calculerMoyenneDes3A(){
        float moy=0f;
        int nb=0;
        for(int i=0; i<nbe ; i++){
            if(T[i] instanceof Etudiant3eme){
                moy += T[i].getMoyenne();
                nb++;
            }
        }
        if (nb == 0) return 0;
        return moy/nb;
    }

    public float calculerMoyenneSalaireAlternants(){
        float moy=0f;
        int nb=0;
        for(int i=0; i<nbe ; i++){
            if(T[i] instanceof EtudiantAlternance){
                moy += T[i].getMoyenne();
                nb++;
            }
        }
        if (nb == 0) return 0;
        return moy/nb;
    }

    @Override
    public String toString() {
        String ch;
        ch = "Ecole{" +"nom='" + nom + '\'' +", etudiants=";
        for (int i = 0; i < nbe; i++) {
            ch += T[i].toString() + "\n";
        }
        ch += '}';
        return ch;
    }


    public static void changerEcole(Etudiant etd, Ecole nouvelleEcole) throws EtudiantExisteException {
        nouvelleEcole.ajouterEtudiant(etd);
    }

}

class Etudiant {
    protected int CIN;
    protected String nom;
    protected String prenom;
    protected float moyenne;

    Etudiant (int c, String n, String p , float moy){
        CIN = c;
        nom = n;
        prenom=p;
        moyenne = moy;
    }


    public int getCIN() {
        return CIN;
    }
    public void setCIN(int CIN) {
        this.CIN = CIN;
    }
    public String getNom() {
        return nom;
    }
    public void setNom(String nom) {
        this.nom = nom;
    }
    public String getPrenom() {
        return prenom;
    }
    public void setPrenom(String prenom) {
        this.prenom = prenom;
    }
    public float getMoyenne() {
        return moyenne;
    }
    public void setMoyenne(float moyenne) {
        this.moyenne = moyenne;
    }


    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Etudiant)) {
            return false;
        }
        else{
            Etudiant etudiant = (Etudiant) obj;
            return CIN == etudiant.CIN && nom.equals(etudiant.nom);
        }
    }

    @Override
    public String toString(){
        return "Etudiant{" + "CIN=" + CIN +", nom=' " + nom + '\'' +", prenom='" + prenom + '\'' +", moyenne=" + moyenne +'}';
    }

    void ajouterUneAbsence(){
    }
}
class Etudiant3eme extends Etudiant{
    private String branche;
    Etudiant3eme (int c, String n, String p , float moy, String b){
        super(c,n,p,moy);
        branche = b; 
    }

    @Override
    void ajouterUneAbsence(){
        setMoyenne( getMoyenne() -0.5f );
    }

}

class EtudiantAlternance extends Etudiant{
    private int salaire; 
    EtudiantAlternance (int c, String n, String p , float moy, int s){
        super(c,n,p,moy);
        salaire =s;
    }

    @Override
    void ajouterUneAbsence(){
        salaire = salaire -50 ;
    }

    @Override
    public String toString(){
        return "EtudiantAlternance{" + "CIN=" + getCIN() +", nom=' " + getNom() + '\'' +", prenom='" + getPrenom() + '\'' +", moyenne=" + getMoyenne() +", salaire="+ salaire +'}' ;
    }

}



class EtudiantExisteException extends Exception {
    public EtudiantExisteException(String message) {
        super(message);
    }
}

public class Main {
    public static void main(String[] args) {
        Ecole ecole = new Ecole("Ecole de Naddou DS");

        Etudiant3eme etudiant3eme = new Etudiant3eme(1, "Rached", "Sima", 20.0f, "iot");
        //Etudiant3eme etudiant3eme2 = new Etudiant3eme(1, "Rached", "Sima", 20.0f, "iot");

        EtudiantAlternance etudiantAlternance = new EtudiantAlternance(2, "Temimi", "Melek", 20.0f, 5000);

        try {
            ecole.ajouterEtudiant(etudiant3eme);
           // ecole.ajouterEtudiant(etudiant3eme2);

            ecole.ajouterEtudiant(etudiantAlternance);
            System.out.println(ecole.toString());
        } catch (EtudiantExisteException e) {
            System.out.println(e.getMessage());
        }
        try {
            Ecole nouvelleEcole = new Ecole("Ecole de Naddou IOT ");
            Ecole.changerEcole(etudiant3eme, nouvelleEcole);
            System.out.println(nouvelleEcole.toString());
        } catch (EtudiantExisteException e) {
            System.out.println(e.getMessage());
        }

    }
}