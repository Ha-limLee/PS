'use strict';

const readline = require('readline');
function getline(){
    let rl = readline.createInterface({
        input: process.stdin,
    });

    return new Promise(function(resolve){
        rl.on('line', (input)=>{
            resolve(input);
            rl.close();
        });
    });
}

function Container(x_width, y_width){
    this.x_width = x_width;
    this.y_width = y_width;

    this.arr = new Array(this.x_width+2);
    for (let i = 0; i < (this.x_width+2); ++i){
        this.arr[i] = new Array(this.y_width+2);
        for (let j = 0; j < (this.y_width+2); ++j)
            this.arr[i][j] = 0;
    }
}
Container.prototype.addAt = function(x, y){
    this.arr[x+1][y+1] = 1;
};
Container.prototype.checkAround = function(i, j){
    if (this.arr[i][j] !== 0){
        this.arr[i][j] = 0;

        this.checkAround(i, j+1);
        this.checkAround(i, j-1);
        this.checkAround(i-1, j);
        this.checkAround(i+1, j);
    }
    else {
        return;
    }
}
Container.prototype.solve = function(){
    let total = 0;
    for (let i = 1; i <= this.x_width; ++i){
        for (let j = 1; j <= this.y_width; ++j){
            if (this.arr[i][j] !== 0){
                ++total;
                this.checkAround(i, j);
            }
        }
    }
    return total;
};

(async function main(){
    let T = await getline();
    T = parseInt(T);
    let nums = [];
    let point = [];
    
    for (let i = 0; i < T; ++i){
        nums = await getline();
        nums = nums.split(' ');

        let container = new Container(parseInt(nums[0]), parseInt(nums[1]));

        for (let k = 0; k < parseInt(nums[2]); ++k){
            point = await getline();
            point = point.split(' ');
            container.addAt(parseInt(point[0]), parseInt(point[1]));
        }
        console.log(container.solve());
        container = undefined;
    }
})();