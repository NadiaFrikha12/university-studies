class Vehicule{
    boolean moteur; 
    int nbPneus ;

    Vehicule (boolean m, int n){
        moteur = m;
        nbPneus=n;
    }

    public boolean getMoteur() {
        return moteur;
    }

    public int getNbPneus(){
        return nbPneus;
    }

    public void  afficher(){
        System.out.println("moteur : " + getMoteur() + "  nbpneus : " + getNbPneus());
    }

}


class Automobile extends Vehicule{
    int nbCylindres;
    int puissanceCylindre;

    Automobile (boolean m, int n, int c, int p){
        super(m,n);
        nbCylindres = c;
        puissanceCylindre=p;
    }

    public int getPuissance(){
        return nbCylindres*puissanceCylindre;
    }

    public void Puissance(int p){
        puissanceCylindre = p;
    }

    public void setNbCylindre(int n){
        nbCylindres = n ;
    }

   @Override
    public void afficher() {
        super.afficher();
        System.out.println(" nbcylindres : " + nbCylindres + " nbpneus : " + nbPneus );
        //redéfinition 
   }

   public void afficher (int nbp){
        System.err.println("nbpneus" + nbp);
        afficher();
        //surcharge
   }
}



public class TestVehicule {
    public static void main(String args[]){
        Vehicule v= new Automobile(false, 0, 0, 0);
        if(v instanceof Automobile){
            System.out.println("Automobile");
        }
        ((Automobile)v).getPuissance();
    }
}
      
