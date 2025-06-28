import { ApplicationConfig, provideZoneChangeDetection } from '@angular/core';
import { provideRouter } from '@angular/router';

import { routes } from './app.routes';
import { HIGHLIGHT_OPTIONS } from 'ngx-highlightjs';
import { CodeThemeService } from './Services/code-theme.service';
import { provideHttpClient } from '@angular/common/http';


export const appConfig: ApplicationConfig = {
  providers: [
    provideZoneChangeDetection({ eventCoalescing: true }),
    provideRouter(routes),
    {
      provide: HIGHLIGHT_OPTIONS,
      useValue: {
        coreLibraryLoader: () => import('highlight.js/lib/core'),
        languages: () => ({
          javascript: () => import('highlight.js/lib/languages/javascript'),
          typescript: () => import('highlight.js/lib/languages/typescript'),
          html: () => import('highlight.js/lib/languages/xml'), 
          css: () => import('highlight.js/lib/languages/css'),
          python: () => import('highlight.js/lib/languages/python'),
          java: () => import('highlight.js/lib/languages/java'),
          csharp: () => import('highlight.js/lib/languages/csharp')
        }),
        autoDetection: true
      }
    }
    ,
    CodeThemeService,
    provideHttpClient()
  ]
};

export function hljsLanguages() {
  return {
    javascript: () => import('highlight.js/lib/languages/javascript'),
    typescript: () => import('highlight.js/lib/languages/typescript'),
    html: () => import('highlight.js/lib/languages/xml'), // 'html' is referred to as 'xml'
    css: () => import('highlight.js/lib/languages/css'),
    python: () => import('highlight.js/lib/languages/python'),
    java: () => import('highlight.js/lib/languages/java'),
    csharp: () => import('highlight.js/lib/languages/csharp')
  };
}