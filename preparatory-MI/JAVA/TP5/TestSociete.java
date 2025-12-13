import java.sql.Date;

class Employe {
    String nom, prenom, adresse, matricule;
    Date date_emb;
    int CIN;
    double salaire;

    Employe (String n, String p, String a, String m, Date d, int c, double s){
        nom = n;
        prenom =p;
        adresse = a; 
        matricule = m;
        date_emb = d;
        CIN = c;
        salaire = s; 
    }
}

class EmployeAssure extends Employe {
    int CNSS; 
    Date dateins;

    EmployeAssure(String n, String p, String a, String m, Date d, int c, double s, int C, date date){
        super(n,p,a,m,d,c,s);
        CNSS = C;
        dateins = date;
    }
}

class EmplyeNonAssure extends Employe{}


public class TestSociete {
    
}


