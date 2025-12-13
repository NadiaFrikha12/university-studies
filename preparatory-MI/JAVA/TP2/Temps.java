public class Temps {
    private int heure;
    private int minute;
    private int seconde;

    Temps (int heure){
        if (heure < 0 || heure >23){
            System.out.println("heure invalide"); 
        }
        else {
            this.heure = heure; 
        }
    }

    Temps (int heure, int minute ){
        if (heure < 0 || heure >23){
            System.out.println("heure invalide"); 
        }
        else if (minute <0 || minute >59 ){
            System.out.println("minute invalide"); 
        }
        else {
            this.heure = heure; 
            this.minute = minute;
        }
       
       
    }

    Temps (int heure, int minute, int seconde ){
        if (heure < 0 || heure >23){
            System.out.println("heure invalide"); 
        }
        else if (minute <0 || minute >59 ){
            System.out.println("minute invalide"); 
        }
        else if (seconde <0 || seconde >59 ){
            System.out.println("seconde invalide"); 
        }
        else {
            this.heure = heure; 
            this.minute = minute;
            this.seconde = seconde; 
        }
    }

    void affiche(){
        System.out.println("Il est " + this.heure + "heures " + this.minute + "minutes "+ this.seconde + "secondes");
    }

    public static void main (String[] args){
        Temps t = new Temps(10); t.affiche();
        t = new Temps(10,12); t.affiche();
        t = new Temps(10,12,45); t.affiche();
    }
}
