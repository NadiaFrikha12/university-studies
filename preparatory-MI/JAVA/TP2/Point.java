public class Point{
    private double x;
    private double y;

    Point(double a, double b){
        x = a;
        y = b;
    }

    void affiche () {
        System.out.println("p= (" + x + "," + y +")");
    }

    void translate(double dx, double dy){
        x += dx; 
        y += dy; 
    } 

    public static void main (String[] args){
        Point p = new Point (2.5, 7 ); 
        p.affiche();
        p.translate(2.,3);
        p.affiche();
    }

}