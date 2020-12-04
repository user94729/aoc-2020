
import java.util.List;
import java.io.*;
import java.nio.file.*;
import java.util.*;

public class r1{
	
	private static final List<String> requiredData = Arrays.asList(new String[]{"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"});
	
	public static void main(String[] args) throws IOException{
		List<String> lines = Files.readAllLines(Paths.get("input"));

		int totalValid = 0;
		int total = 0;

		String lastPassport = "";
		for(String s : lines){
			if(s.length() < 1){
				String[] passportData = lastPassport.split(" ");
				int validCount = 0;
				for(String p : passportData){
					if(requiredData.indexOf(p.split(":")[0]) >= 0)
						validCount++;
				}
				if(validCount == requiredData.size())
					totalValid++;
				total++;
				lastPassport = "";
			}else{
				lastPassport += (lastPassport.length() > 0 ? " " : "") + s;
			}
		}

		System.out.println(totalValid + " valid of " + total);
	}
}
