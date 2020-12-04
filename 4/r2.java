
import java.util.List;
import java.io.*;
import java.nio.file.*;
import java.util.*;
import java.util.regex.*;

public class r2{

	private static final List<String> requiredData = Arrays.asList(new String[]{"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"});

	private static final List<String> validEyeColors = Arrays.asList(new String[]{"amb", "blu", "brn", "gry", "grn", "hzl", "oth"});

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
					String[] data = p.split(":");
					if(data.length < 2)
						continue;
					switch(data[0]){ // requires JDK >= 7
						case "byr": {
							int num = Integer.parseInt(data[1]);
							if(num >= 1920 && num <= 2002)
								validCount++;
							break;
						}
						case "iyr": {
							int num = Integer.parseInt(data[1]);
							if(num >= 2010 && num <= 2020)
								validCount++;
							break;
						}
						case "eyr": {
							int num = Integer.parseInt(data[1]);
							if(num >= 2020 && num <= 2030)
								validCount++;
							break;
						}
						case "hgt": {
							if(data[1].length() < 3)
								continue;
							int num = Integer.parseInt(data[1].substring(0, data[1].length() - 2));
							if(data[1].endsWith("cm"))
								validCount += (num >= 150 && num <= 193) ? 1 : 0;
							else if(data[1].endsWith("in"))
								validCount += (num >= 59 && num <= 76) ? 1 : 0;
							break;
						}
						case "hcl": {
							if(Pattern.compile("^#[0-9a-f]{6}$").matcher(data[1]).matches())
								validCount++;
							break;
						}
						case "pid": {
							if(Pattern.compile("^[0-9]{9}$").matcher(data[1]).matches())
								validCount++;
							break;
						}
						case "ecl": {
							if(validEyeColors.indexOf(data[1]) >= 0)
								validCount++;
							break;
						}
					}
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
