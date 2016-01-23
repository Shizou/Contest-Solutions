import java.util.Scanner;

public class semafori {
    public static void main(String[]args){
        Scanner s = new Scanner(System.in);

        int lights = s.nextInt();
        int distance = s.nextInt();
        int currDistance = 0;
        int seconds = 0;

        int[][] data = new int[lights][4];
        boolean[] on = new boolean[lights];

        for(int i = 0;i < lights;i++){
            for(int j = 0;j < 3;j++){
                data[i][j] = s.nextInt();
            }
            data[i][3] = 0;
            on[i] = false;
        }

        for(int pos = 0; currDistance != distance;pos++){
            if(pos < lights){
                while( currDistance <= data[pos][0]){
                    seconds++;
                    if(currDistance != data[pos][0])
                        currDistance++;
                    for(int j = 0;j < lights;j++){
                        data[j][3]++;
                        if(on[j] == true){
                            if(data[j][3] == data[j][2]){
                                data[j][3] = 0;
                                on[j] = false;
                            }
                        }
                        else if(on[j] == false){
                            if(data[j][3] ==  data[j][1]){
                                data[j][3] = 0;
                                on[j] = true;
                            }
                        }
                    }
                    if(currDistance == data[pos][0]){
                        if(on[pos] == true)
                            break;
                        else
                            continue;

                    }
                }

            }
            else{
                currDistance++;
                seconds++;
            }
        }
        System.out.println(seconds);
    }
}