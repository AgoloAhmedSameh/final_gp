import { TestBed } from '@angular/core/testing';

import { CodeThemeService } from './code-theme.service';

describe('CodeThemeService', () => {
  let service: CodeThemeService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(CodeThemeService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
