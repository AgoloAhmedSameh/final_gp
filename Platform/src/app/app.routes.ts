import { Routes } from '@angular/router';

export const routes: Routes = [
    {
        path: '',
        pathMatch: 'full',
        loadComponent() {
            return import('./login-page/login-page.component').then(
                m => m.LoginPageComponent
            );
        },
    },
    {
        path: 'home-page',
        loadComponent() {
            return import('./home-page/home-page.component').then(
                m => m.HomePageComponent
            );
        },
    },
    {
        path: 'full-report-page',
        loadComponent() {
            return import('./output-menu/output-menu.component').then(
                m => m.OutputMenuComponent
            );
        },
    },

];
