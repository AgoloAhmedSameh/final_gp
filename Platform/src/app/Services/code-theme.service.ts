import { Injectable, Inject, PLATFORM_ID } from '@angular/core';
import { isPlatformBrowser } from '@angular/common';
import "prismjs";
import "prismjs/components/prism-pug.js";
import "prismjs/components/prism-scss.js";
import "prismjs/components/prism-typescript.js";
import "prismjs/components/prism-java.js";
import "prismjs/components/prism-javascript.js";
import "prismjs/components/prism-markup.js";
import "prismjs/components/prism-python.js";
import "prismjs/components/prism-core";  // Ensure the core is loaded
import "prismjs/components/prism-clike"; // Needed for C-based languages
import "prismjs/plugins/toolbar/prism-toolbar";
import "prismjs/plugins/show-language/prism-show-language";
import 'prismjs/plugins/line-numbers/prism-line-numbers.js';

declare var Prism: any;


@Injectable({
  providedIn: 'root'
})

export class CodeThemeService {

  constructor(
    @Inject(PLATFORM_ID) private readonly _platformId: Object
  ) { 

  }

  public HighlightAll()
  {
    if(isPlatformBrowser(this._platformId))
    {
      Prism.highlightAll();
    }
  }

  convertHtmlIntoString(text:string | null | undefined)
  {
    return text!
    .replace(new RegExp('&','g'), '&amp;')
    .replace(new RegExp('<', 'g'), '&lt;');
  }

}
