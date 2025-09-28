//1. Crée une variable id qui peut être soit un number, soit un string.
let id:number|string;

//2. Crée deux types A et B, puis fais-en une intersection.
type A = {
    a:number
};

type B = {
    b:string
};

type C = A & B ;

const objet:C = {
    a : 1,
    b : "hello",
}

//3. Crée un alias Status qui peut valoir "pending", "done" ou "canceled".
type Status = "pending" | "done" | "canceled";

//4. Déclare une variable unknown et utilise une assertion de type pour accéder à sa longueur si c’est une chaîne.
let a:unknown = "hello";

let lenght = (a as string).length;
console.log(lenght);