class Point{
    protected double x;
    protected double y;

    Point(double a, double b){
        x=a;
        y=b;
    }

    @Override 
    public string toString(){  
        return 
    }
}

class Cercle extends Point{

    public static final double PI = 3.14;

    protected double rayon;

    Cercle (double a, double b, double c){
        super(a,b);
        rayon = c; 
    }

    public double surface(){
        return PI*rayon*rayon;
    }
}

class Cylindre extends Cercle{

    public static final double PI = 3.14;

    private double hauteur;

    Cylindre (double a, double b, double c, double d){
        super(a,b,c);
        hauteur = d; 
    }

    public double surface(){
        double s = 2*PI*rayon*rayon + 2*PI*rayon*hauteur;
        return s;
    }
}

public class Test {
    public static void main( String[] args){
        /* un point est défini par ses coordonnées x et y */
        Point p = new Point(2.0, 2.0);
        System.out.println("Point -> " + p);
        /*un cercle est défini par les coordonnées x et y de son centre et par son rayon */
        Cercle c= new Cercle (2.0, 2.0, 3.0);
        System.out.println("Cercle -> " + c+ ", surface :"+ c.surface());
        /*un Cylindre est défini par les coordonnées x et y de son centre, rayon et par sa hauteur */
        Cylindre cc= new Cylindre (2.0, 2.0, 3.0, 10.0);
        System.out.println("Cylindre -> " + cc+ ", surface :"+ cc.surface());

    }
}


/*
 * System.out.println("Point -> " + p);
 * Point ->Point @3fee733d
 * => il va être compris comme un objet donc il affiche une adresse
 * 
 * System.out.println("Point -> " + p);
 * p au lieu de p.toString() parce que c'est un appel implicite de s.o.p
 * p.toString() appel explicite
 */

