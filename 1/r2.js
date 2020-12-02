
let fs = require('fs');



let lines = fs.readFileSync("input").toString().replace(/\r/g, "").split("\n");

let nums = [];

let start = Date.now();

for(let l of lines){
	let num = parseInt(l);
	if(Number.isNaN(num))
		console.log("Ignoring invalid number: " + l);
	else
		nums.push(num);
}

for(let i = 0; i < nums.length; i++){
	for(let j = i; j < nums.length; j++){
		if(nums[i] + nums[j] >= 2020)
			continue;
		for(let k = j; k < nums.length; k++){
			if(nums[i] + nums[j] + nums[k] == 2020){
				console.log(" " + i + " " + j + " " + k);
				console.log(" --nums: " + nums[i] + " " + nums[j] + " " + nums[k]);
				console.log(" --mul: " + (nums[i] * nums[j] * nums[k]));
			}
		}
	}
}

console.log("time: " + (Date.now() - start) + "ms");



