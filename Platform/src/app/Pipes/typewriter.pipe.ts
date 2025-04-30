import { Pipe, PipeTransform } from '@angular/core';
import { Observable, of } from 'rxjs';
import { delay, concatMap } from 'rxjs/operators';

@Pipe({
  name: 'typewriter'
})
export class TypewriterPipe implements PipeTransform {
  transform(value: string): Observable<string> {
    if (!value) return of('');

    let textArray = value.split('');
    let time = 20; // Initial delay in ms

    return new Observable<string>((observer) => {
      let output = '';
      textArray.reduce((prev, char, index) => {
        return prev.pipe(
          delay(time += 20), // Increase delay for each character
          concatMap(() => {
            output += char;
            observer.next(output);
            return of(output);
          })
        );
      }, of('')).subscribe({
        complete: () => observer.complete(),
      });
    });
  }
}
