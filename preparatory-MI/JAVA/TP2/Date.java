public class Date {
    private int jour;
    private int mois;
    private int annee;

    Date ( int j , int m, int a){
        jour = j;
        mois = m; 
        annee = a;
    }

    int nombreJour (int j ,int m, int a){ //on ne donne pas argument Date et lors de l'appel on ecrit objet.methode
        jour = j;
        mois = m;
        annee = a;
        switch(mois){
            case 1 : return 31; 
            case 2 : 
                if (annee % 4 == 0) {
                    return 28;
                } 
                else {
                    return 29;
                } 
        
            case 3 : case 5 : case 7 : case 10 : case 12 :   case 8 : return 31; 
            case 4 : case 6 : case 9 :  case 11 : return 30; 
            default: return -1;   
        }      
        //attention : il faut toujours donner le cas default   
        //generalement on n'ecrit pas break apres return  
    }

    int dateValide(){
        if (jour<=0 || jour>31){
            return 1;
        }

        else if (mois<=0 || mois>12){
            return 1;
        }

        else if (annee<=1000 || annee> 9999){
            return 1;
        }

        else{
            if (nombreJour(jour, mois,annee) == jour){
                return 0 ; 
            }
            else {
                return 1 ;
            }
        }
    }

    Date lendemain(){
        if (dateValide(jour, mois, annee) == 1 ){
            System.out.println("date invalide");
        }
        else{ 
            if (d.jour == nombreJour(d)){
                d.jour = 1; 
                if (d.mois <=11){
                    d.mois += 1; 
                }
                else{
                    d.mois = 1;
                    d.annee += 1 ;
                }
            }
            else{
                d.jour +=1; 
            }
        }
    }


}
