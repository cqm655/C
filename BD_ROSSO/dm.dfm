object dm1: Tdm1
  OldCreateOrder = False
  Height = 348
  Width = 555
  object FDConnection1: TFDConnection
    Params.Strings = (
      'Database=incaltaminte'
      'Server=PC-LITE'
      'OSAuthent=Yes'
      'DriverID=MSSQL')
    Connected = True
    LoginPrompt = False
    Left = 16
    Top = 16
  end
  object qliber: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'select * from pantof')
    Left = 56
    Top = 160
  end
  object qshow: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      
        'SELECT p.pantof_id,ig.indice_grupa_id,ig.indice_grupa as tip, p.' +
        'model,m.material_id, m.MATERIAL as Material,'
      '       c.culoare_id, c.CULOARE as culoare,'
      
        '       p.m39 as [39],p.m40 as [40], p.m41 as [41],p.m42 as [42],' +
        ' p.m43 as [43],p.m44 as [44],p.m45 as [45],'
      #9'   p.PRET'
      '        FROM PANTOF P '
      
        '        INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDIC' +
        'E_GRUPA_ID'
      '        INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID'
      #9'INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID'
      #9'INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID'
      #9'WHERE S.SEZON='#39'VARA'#39' and p.activ=1  '
      #9#9#9#9#9'   ')
    Left = 192
    Top = 8
  end
  object dsqshow: TDataSource
    DataSet = qshow
    Left = 160
    Top = 8
  end
  object qedit: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'UPDATE PANTOF SET'
      'INDICE_GRUPA_ID=:INDICE_GRUPA_ID,'
      'Model=:Model,'
      'MATERIAL_ID=:MATERIAL_ID,'
      'CULOARE_ID=:CULOARE_ID,'
      'M39=:M39,'
      'M40=:M40,'
      'M41=:M41,'
      'M42=:M42,'
      'M43=:M43,'
      'M44=:M44,'
      'M45=:M45,'
      'PRET=:PRET'
      'WHERE PANTOF_ID=:PANTOF_ID'
      '')
    Left = 56
    Top = 208
    ParamData = <
      item
        Name = 'INDICE_GRUPA_ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'MODEL'
        DataType = ftString
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'MATERIAL_ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'CULOARE_ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'M39'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'M40'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'M41'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'M42'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'M43'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'M44'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'M45'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'PRET'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end
      item
        Name = 'PANTOF_ID'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
  end
  object qtip: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'select indice_grupa_id, indice_grupa from INDICE_GRUPA')
    Left = 352
    Top = 184
  end
  object dsqtip: TDataSource
    DataSet = qtip
    Left = 296
    Top = 184
  end
  object dsqculoare: TDataSource
    DataSet = qculoare
    Left = 296
    Top = 272
  end
  object dsqmaterial: TDataSource
    DataSet = qmaterial
    Left = 296
    Top = 232
  end
  object qmaterial: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'select * from material')
    Left = 352
    Top = 232
  end
  object qculoare: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'select * from culoare')
    Left = 352
    Top = 280
  end
  object qgol: TFDQuery
    Connection = FDConnection1
    Left = 464
    Top = 16
  end
  object qshowiarna: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      
        'SELECT p.pantof_id,ig.indice_grupa_id,ig.indice_grupa as tip, p.' +
        'model as Model,m.material_id, m.MATERIAL as Material,'
      '       c.culoare_id, c.CULOARE as culoare,'
      
        '       p.m39 as [39],p.m40 as [40], p.m41 as [41],p.m42 as [42],' +
        ' p.m43 as [43],p.m44 as [44],p.m45 as [45],'
      #9'   p.PRET'
      '        FROM PANTOF P '
      
        '        INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDIC' +
        'E_GRUPA_ID'
      '        INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID'
      #9'INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID'
      #9'INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID'
      ''
      #9'WHERE S.SEZON='#39'iarna'#39' and p.activ=1  '
      #9#9#9#9#9'   ')
    Left = 208
    Top = 56
  end
  object dsqiarna: TDataSource
    DataSet = qshowiarna
    Left = 144
    Top = 56
  end
  object dsqgol: TDataSource
    DataSet = qgol
    Left = 416
    Top = 16
  end
  object qgol2: TFDQuery
    Connection = FDConnection1
    Left = 504
    Top = 16
  end
  object qsp: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      
        'SELECT p.pantof_id,ig.indice_grupa_id,ig.indice_grupa as tip, p.' +
        'model as Model,m.material_id, m.MATERIAL as Material,'
      '       c.culoare_id, c.CULOARE as culoare,'
      
        '       p.m39 as [39],p.m40 as [40], p.m41 as [41],p.m42 as [42],' +
        ' p.m43 as [43],p.m44 as [44],p.m45 as [45],'
      #9'   p.PRET, id.Magazin as Magazin'
      '        FROM PANTOF P '
      
        '        INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDIC' +
        'E_GRUPA_ID'
      '        INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID'
      #9'INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID'
      #9'INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID'
      
        '    INNER JOIN Indice_Spatiu id on id.Indice_spatiu_ID=p.Indice_' +
        'Spatiu_ID'
      #9'WHERE S.SEZON='#39'vara'#39' and p.activ=1 '
      ''
      #9
      #9#9#9#9#9'   ')
    Left = 200
    Top = 112
  end
  object DSSP: TDataSource
    DataSet = qsp
    Left = 144
    Top = 112
  end
  object qsi: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      
        'SELECT p.pantof_id,ig.indice_grupa_id,ig.indice_grupa as tip, p.' +
        'model as Model,m.material_id, m.MATERIAL as Material,'
      '       c.culoare_id, c.CULOARE as culoare,'
      
        '       p.m39 as [39],p.m40 as [40], p.m41 as [41],p.m42 as [42],' +
        ' p.m43 as [43],p.m44 as [44],p.m45 as [45],'
      #9'   p.PRET, id.Magazin as Magazin'
      '        FROM PANTOF P '
      
        '        INNER JOIN INDICE_GRUPA IG ON IG.INDICE_GRUPA_ID=P.INDIC' +
        'E_GRUPA_ID'
      '        INNER JOIN MATERIAL M ON M.MATERIAL_ID=P.MATERIAL_ID'
      #9'INNER JOIN CULOARE C ON C.CULOARE_ID=P.CULOARE_ID'
      #9'INNER JOIN SEZON S ON S.SEZON_ID=P.SEZON_ID'
      
        '    INNER JOIN Indice_Spatiu id on id.Indice_spatiu_ID=p.Indice_' +
        'Spatiu_ID'
      #9'WHERE S.SEZON='#39'IARNA'#39' and p.activ=1  and id.Magazin=1'
      ''
      #9
      #9#9#9#9#9'   ')
    Left = 200
    Top = 168
  end
  object DSSPiarna: TDataSource
    DataSet = qsi
    Left = 144
    Top = 168
  end
end