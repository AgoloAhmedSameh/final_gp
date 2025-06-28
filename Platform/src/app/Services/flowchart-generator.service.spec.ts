import { TestBed } from '@angular/core/testing';

import { FlowchartGeneratorService } from './flowchart-generator.service';

describe('FlowchartGeneratorService', () => {
  let service: FlowchartGeneratorService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(FlowchartGeneratorService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
