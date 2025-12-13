public class Ex1{
    public static void main (String[] args){
        int[] t = {1,2,3,4,5,6,7,8,9,10};
        int l = t.length;
        int aux=0;
        for(int i =0; i< l/2 ; i++){
            aux=t[i];
            t[i]=t[l-i-1];
            t[l-i-1]=aux;
        }

        for(int i=0; i<l; i++){
            System.out.println(t[i]);
        }   
    }
}

/*import java.util.Arays
System.out.println("Arrays.toString(t)") 
System.out.println("t")  => donne adresse => FAUX
 */