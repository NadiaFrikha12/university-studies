//1. Crée une classe Person avec les propriétés name et age, et une méthode greet().
class Person {
    name:string;
    age:number;
    constructor (name:string, age:number){
        this.name = name;
        this.age = age;
    }

    greet(){
        console.log("Hello");
    }
}

//2. Crée une classe Student qui hérite de Person et ajoute une propriété school.
class Student extends Person {
    school:string;

    constructor(name:string, age:number, school:string ){
        super(name,age);
        this.school = school;
    }
}

//3. Crée une classe abstraite Shape avec une méthode abstraite area(), puis implémente Circle et Rectangle.
abstract class Shape {
    abstract area():number ;
}

class Circle extends Shape{
    rayon:number;
    constructor(r:number){
        super();   
        this.rayon = r;
    }
    area(){
        return Math.PI * this.rayon * this.rayon;
    }
}

class Rectangle extends Shape {
    width: number;
    height: number;

    constructor(width: number, height: number) {
        super();
        this.width = width;
        this.height = height;
    }

    area(): number {
        return this.width * this.height;
    }
}

//4. Crée une interface Drivable avec une méthode drive(), puis une classe Car qui l’implémente.
interface Drivable {
    drive(): void;
}

class Car implements Drivable {
    marque: string;

    constructor(marque: string) {
        this.marque = marque;
    }

    drive(): void {
        console.log(`${this.marque} is driving`);
    }
}