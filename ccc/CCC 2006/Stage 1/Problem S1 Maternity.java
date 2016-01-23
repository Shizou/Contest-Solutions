import java.util.*;

public class ccc06s1 {
	public static void main(String[]args){
		Scanner s = new Scanner(System.in);
		
		String parent1  = s.nextLine();
		String parent2 = s.nextLine();
		
		int babies = s.nextInt();
		String baby = "";
		boolean posBaby = true;
		s.nextLine();
		
		for(int i = 0;i < babies;i++){
			baby = s.nextLine();
			
			posBaby = true;
			for(int j = 0;j < 5;j++){
				if(baby.charAt(j) == 'a'){
					if( ( parent1.contains("AA") || parent2.contains("AA") ) ){
						posBaby = false;
						break;
					}
				}
				else if(baby.charAt(j) == 'A'){
					if(!(parent1.contains("A") ||  parent2.contains("A"))){
						posBaby = false;
						break;
					}
				}
				else if(baby.charAt(j) == 'b'){
					if( ( parent1.contains("BB") || parent2.contains("BB") ) ){
						posBaby = false;
						break;
					}
				}
				else if(baby.charAt(j) == 'B'){
					if(!(parent1.contains("B") ||  parent2.contains("B"))){
						posBaby = false;
						break;
					}
				}
				else if(baby.charAt(j) == 'c'){
					if( ( parent1.contains("CC") || parent2.contains("CC") ) ){
						posBaby = false;
						break;
					}
				}
				else if(baby.charAt(j) == 'C'){
					if(!(parent1.contains("C") ||  parent2.contains("C"))){
						posBaby = false;
						break;
					}
				}
				else if(baby.charAt(j) == 'd'){
					if( ( parent1.contains("DD") || parent2.contains("DD") ) ){
						posBaby = false;
						break;
					}
				}
				else if(baby.charAt(j) == 'D'){
					if(!(parent1.contains("D") ||  parent2.contains("D"))){
						posBaby = false;
						break;
					}
				}
				else if(baby.charAt(j) == 'e'){
					if( ( parent1.contains("EE") || parent2.contains("EE") ) ){
						posBaby = false;
						break;
					}
				}
				else if(baby.charAt(j) == 'E'){
					if(!(parent1.contains("E") ||  parent2.contains("E"))){
						posBaby = false;
						break;
					}
				}
			}
			
			if(posBaby)
				System.out.println("Possible baby.");
			else
				System.out.println("Not their baby!");
		
		}
		
		
		
	}
}
