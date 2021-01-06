function read_sync(){
    return new Promise((resolve, reject)=>{
        if (process.stdin.isPaused())
            process.stdin.resume();

        process.stdin.on('data', (data)=>{
            process.stdin.pause();
            resolve(data.toString().trim());
        });
    });
}

function constructors(M){
    let result = M;
    while(M !== 0){
        result += M % 10;
        M = ~~(M/10);
    }
    return result;
}

function solve(N){
    for (let M = ~~(N/2); M <= N; ++M){
        if (N === constructors(M))
            return M;
    }
    return 0;
}

(async function main(){
    let N = Number(await read_sync());
    console.log(solve(N));
})();