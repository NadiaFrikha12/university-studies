//1. Crée une interface User avec les propriétés id: number, name: string, email?: string(optionnelle), et isAdmin: boolean en lecture seule.
interface User {
    id : number;
    name : string;
    email? : string;
    readonly isAdmin : boolean;
}

//2. Crée un objet user1 conforme à cette interface.
const user1:User = {
    id : 123,
    name : "Nadia",
    isAdmin: true
}

//3.Crée une interface Admin qui hérite de User et ajoute une propriété permissions: string[].
interface Admin extends User{
    permissions: string[]; 
}