

import java.util.*;
import java.io.*;


class Contestant{
	int number_of_problems_solved;
	int correct_submissions[] = new int[9];
	int incorrect_submissions[] = new int[9];
	int total_penalty;
}


public class contest_scoreboard {
	
	public void execute() throws FileNotFoundException{
		int num_test_cases;
		Scanner scan = new Scanner(new File("contest_scoreboard.txt"));
		HashSet <Contestant> map= new HashSet<Contestant>();
		num_test_cases = Integer.parseInt(scan.nextLine().trim());
		System.out.println(num_test_cases);
		scan.nextLine();
		String next=null;
		while(num_test_cases-->0){
			while((next=scan.nextLine())!=""){
				
				
			}
			
			
		}
		
		
	}

}
