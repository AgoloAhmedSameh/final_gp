import { ComponentFixture, TestBed } from '@angular/core/testing';

import { OutputMenuComponent } from './output-menu.component';

describe('OutputMenuComponent', () => {
  let component: OutputMenuComponent;
  let fixture: ComponentFixture<OutputMenuComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [OutputMenuComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(OutputMenuComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
