import { bootstrapApplication } from '@angular/platform-browser';
import { appConfig } from './app/app.config';
import { AppComponent } from './app/app.component';
// import 'prismjs/plugins/toolbar/prism-toolbar.css';
// import 'prismjs/plugins/show-language/prism-show-language.css';

bootstrapApplication(AppComponent, appConfig)
  .catch((err) => console.error(err));
