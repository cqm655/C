object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 290
  ClientWidth = 417
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel3: TPanel
    Left = 0
    Top = 0
    Width = 417
    Height = 290
    Align = alClient
    TabOrder = 2
    Visible = False
    object Label3: TLabel
      Left = 104
      Top = 1
      Width = 205
      Height = 45
      Caption = 'Ati Acumulat'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clLime
      Font.Height = -37
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 264
      Top = 81
      Width = 110
      Height = 45
      Caption = 'Puncte'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -37
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 120
      Top = 81
      Width = 20
      Height = 77
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -64
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 417
    Height = 290
    Align = alClient
    Color = clRed
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clLime
    Font.Height = -64
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 0
    object Label1: TLabel
      Left = 80
      Top = 2
      Width = 260
      Height = 77
      Caption = 'TESTARE'
    end
    object Button1: TButton
      Left = 96
      Top = 120
      Width = 233
      Height = 106
      Caption = 'START'
      TabOrder = 0
      OnClick = Button1Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 417
    Height = 290
    Align = alClient
    Caption = 'Panel2'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clLime
    Font.Height = -64
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    ParentShowHint = False
    ShowCaption = False
    ShowHint = False
    TabOrder = 1
    Visible = False
    object Label2: TLabel
      Left = 16
      Top = 16
      Width = 4
      Height = 16
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 318
      Top = 106
      Width = 35
      Height = 77
      Caption = '4'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -64
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object RadioButton1: TRadioButton
      Left = 16
      Top = 128
      Width = 257
      Height = 31
      Caption = 'RadioButton1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clLime
      Font.Height = -20
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 16
      Top = 165
      Width = 296
      Height = 29
      Caption = 'RadioButton1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clLime
      Font.Height = -20
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = RadioButton2Click
    end
    object RadioButton3: TRadioButton
      Left = 16
      Top = 200
      Width = 257
      Height = 17
      Caption = 'RadioButton1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clLime
      Font.Height = -20
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = RadioButton3Click
    end
    object RadioButton4: TRadioButton
      Left = 16
      Top = 232
      Width = 257
      Height = 17
      Caption = 'RadioButton1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clLime
      Font.Height = -20
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = RadioButton4Click
    end
    object Button2: TButton
      Left = 318
      Top = 188
      Width = 75
      Height = 61
      Caption = 'NEXT'
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clLime
      Font.Height = -20
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnClick = Button2Click
    end
    object ProgressBar1: TProgressBar
      Left = 16
      Top = 264
      Width = 376
      Height = 17
      Max = 99
      TabOrder = 5
    end
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 264
    Top = 136
  end
end
