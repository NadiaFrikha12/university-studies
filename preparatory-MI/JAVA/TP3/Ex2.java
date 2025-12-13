public class Ex2 {
    public static void main (String[] args){
        int[] t = {1,2,3,4,5,6,7,8,9,10};
        int l = t.length;

        if(l<2){
            System.out.println(0);      
        }

        int gap=0;
        int min =t[1]-t[0];
        
        for(int i =1; i< (l-1) ; i++){
            gap = t[i+1]-t[i];
            if (gap<min){
                min =gap;
            }
        }

        System.out.println(min);
    }
}

/*
int min = Interger.MAX_VALUE; (MAX_VALUE = 2^32 -1 )
 */
