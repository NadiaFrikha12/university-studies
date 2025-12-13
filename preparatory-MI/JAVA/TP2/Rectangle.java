public class Rectangle {
    private float longueur ;
    private float largeur ;

    Rectangle(){
        longueur = 12;
        largeur = 7;
    }

    Rectangle (float longueur, float largeur){
        this.longueur = longueur;
        this.largeur = largeur ;
    }

    
    void modifierRectangle( float lon, float lar){
        longueur = lon; 
        largeur = lar; 
    }

    float perimetre() {
        return (longueur + largeur)*2 ;
    }

    float surface(){
        return (longueur * largeur);
    }

    void affichage(){
        System.out.println("longueur : "+ longueur);
        System.out.println("largeur : "+ largeur );
        System.out.println("perimetre  : "+ this.perimetre() );
        System.out.println("surface  : "+ this.surface() );
    }

    public static void main (String[] args){
        //utilisation constructeur avec paramètres
        Rectangle r1 = new Rectangle(7.5f, 3.8f);
        System.out.println("Informations sur r1 : ");
        r1.affichage();

        //utilisation constructeur sans paramètres
        Rectangle r2 = new Rectangle();
        System.out.println("Informations sur r2 : ");
        r2.affichage();

        r2.modifierRectangle(16.3f, 15f);
        System.out.println("Informations sur r2 aprés modification  : ");
        r2.affichage();

    }

    //lorsqu"on déclare un constructeur, le constructeur par défaut sera écrasé
    
}
