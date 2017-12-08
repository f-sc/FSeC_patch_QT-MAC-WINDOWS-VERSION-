object Form3: TForm3
  Left = 0
  Top = 0
  Anchors = [akRight]
  BorderStyle = bsToolWindow
  Caption = 'Set new value'
  ClientHeight = 103
  ClientWidth = 265
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  PopupMode = pmAuto
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 30
    Width = 27
    Height = 13
    Caption = 'Data:'
  end
  object Label2: TLabel
    Left = 50
    Top = 8
    Width = 171
    Height = 13
    Caption = 'Take care: 2 digits only(sample: 75)'
  end
  object Edit1: TEdit
    Left = 41
    Top = 27
    Width = 192
    Height = 21
    MaxLength = 2
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
  end
  object Button1: TButton
    Left = 41
    Top = 70
    Width = 75
    Height = 25
    Caption = 'Confirm'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 158
    Top = 70
    Width = 75
    Height = 25
    Caption = 'Close'
    TabOrder = 2
    OnClick = Button2Click
  end
end
