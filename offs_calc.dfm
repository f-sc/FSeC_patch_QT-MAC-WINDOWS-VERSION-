object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = 'Calculator'
  ClientHeight = 145
  ClientWidth = 275
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 104
    Top = 56
    Width = 42
    Height = 24
    Caption = '------'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 16
    Top = 11
    Width = 23
    Height = 13
    Caption = 'HEX:'
  end
  object Label3: TLabel
    Left = 16
    Top = 65
    Width = 24
    Height = 13
    Caption = 'DEC:'
  end
  object Edit1: TEdit
    Left = 64
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object Button1: TButton
    Left = 88
    Top = 112
    Width = 75
    Height = 25
    Caption = 'Calculate'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 200
    Top = 0
    Width = 75
    Height = 145
    Caption = 'Close'
    TabOrder = 2
    OnClick = Button2Click
  end
end
