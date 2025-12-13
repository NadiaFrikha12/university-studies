//1. Crée une fonction add(a: number, b: number): number.
function add (a: number, b: number):number {
    return a+b; 
}

//2. Crée une fonction greet(name: string, age?: number) qui affiche un message différent selon si l’âge est fourni ou non.
function greet (name: string, age?: number):void {
    if (age){
        console.log("you won ", name);
    }
    else{
        console.log("you lose ",name);
    }
}

//3. Crée une fonction power(base: number, exp: number = 2) qui calcule une puissance avecun exposant par défaut.
function power (base: number, exp: number = 2):number{
    return base*exp;
}

//4. Crée une fonction combine qui soit peut additionner deux nombres, soit concaténer deux chaînes (surcharge).
function combine (a:number, b:number):number;

function combine (a:string, b:string):string;

function combine (a:any, b:any): any {
    return a+b;
}