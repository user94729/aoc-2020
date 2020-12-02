
let fs = require('fs');



let lines = fs.readFileSync("input").toString().replace(/\r/g, "").split("\n");

let nums = [];

for(let l of lines){
	let num = parseInt(l);
	if(Number.isNaN(num))
		console.log("Ignoring invalid number: " + l);
	else
		nums.push(num);
}

let indices = [];

for(let i = 0; i < nums.length; i++){
	for(let j = 0; j < nums.length; j++){
		for(let k = 0; k < nums.length; k++){
			if(nums[i] + nums[j] + nums[k] == 2020){
				console.log(" " + i + " " + j + " " + k);
				console.log(" --nums: " + nums[i] + " " + nums[j] + " " + nums[k]);
				indices[0] = i;
				indices[1] = j;
				indices[2] = k;
				let num = 1;
				for(let n of indices)
					num *= nums[n];
				console.log(" --mul: " + num);
			}
		}
	}
}

console.log(indices.length + " indices");

let num = 1;
for(let n of indices)
	num *= nums[n];
console.log(num);



