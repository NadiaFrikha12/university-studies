public class Compte {
    private int numeroCompte;
    private double solde; 

    Compte (int num, double s){
        numeroCompte = num;
        solde = s; 
    }

    double getSolde(){

    }

    int autoriser(){

    }

    void deposer(double s){
        solde += s;
    }

    void retirer (double s){
        if (s > solde){
            System.out.println("vous ne pouvez pas retirer de l'argent");
        }
        else{
            solde -= s;
        }
    }

    void afficher(){
        System.out.println("numero du compte : "+ numeroCompte );
        System.out.println("solde du compte : "+ solde );
    }
}
