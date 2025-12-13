import java.util.Scanner;  

public class Ex6 {
    public static void main (String[] args){
        int[][] t = new int[5][5];

        Scanner scanner = new Scanner (System.in);
        
        while(true) {
            System.out.println("Saisir le numero de l'operation");
            System.out.println("1.remplir la matrice");
            System.out.println("2.supprimer une ligne");
            System.out.println("3.afficher la matrice");
            System.out.println("4.tester si le tableau est magique");
            System.out.println("5.exit");
            
            char c = scanner.next().charAt(0); 

            switch (c) {
                case '1':
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        System.out.print("Donner t[" + i + "][" + j + "] : ");
                        int nombre = scanner.nextInt();
                
                        while (nombre < 0) {
                            System.out.println("Erreur ");
                            nombre = scanner.nextInt();
                        }
                        t[i][j] = nombre;
                    }
                }
                break;


                case '2':
                System.out.println("donner numero ligne à supprimer ");
                int ligne = scanner.nextInt();  
                while (ligne < 0 || ligne >= 5) {
                    System.out.println("Erreur");
                    ligne = scanner.nextInt();  
                }

                for (int i= ligne; i<4; i++){
                    for(int j=0; j<5; j++){
                        t[i][j]=t[i+1][j];
                    }
                }
                
                for (int i =0; i<5; i++){
                    t[4][i]=0;
                }

                break;
            
                case '3':
                for (int i = 0; i<5; i++){
                    for(int j =0; j<5;j++){
                        System.out.print(t[i][j] + "\t");
                    }
                    System.out.print("\n");
                }
                break;

                case '4' : 
                int somme =0;
                for (int i = 0; i < 5 ; i++) {
                    somme += t[0][i];
                }

                //lignes + colonnes
                boolean estMagique = true;

                for (int i = 0; i < 5; i++) {
                    int sommeLigne = 0;
                    int sommeColonne = 0;
                    
                    for (int j = 0; j < 5 ; j++) {
                        sommeLigne += t[i][j];  
                        sommeColonne += t[j][i]; 
                    }

                    if (sommeLigne != somme || sommeColonne != somme) {
                        estMagique = false;
                        break;
                    }
                }

                //diagonales
                if (estMagique) {
                    int sommeDiag = 0, sommeDiagInv = 0;

                    for (int i = 0; i < 5; i++) {
                        sommeDiag += t[i][i];                   
                        sommeDiagInv += t[i][4 - i];   
                    }

                    if (sommeDiag != somme || sommeDiagInv != somme) {
                        estMagique = false;
                    }
                }

            
                if (estMagique) {
                    System.out.println("la matrice est magique ");
                }
                else {
                    System.out.println("La matrice n'est pas magique");
                }

                break;


                case '5': 
                System.out.println("Programme terminé");
                scanner.close();
                return;

                default:
                    System.out.println("Choix invalide, veuillez réessayer.");
                }
        }

    }
}


